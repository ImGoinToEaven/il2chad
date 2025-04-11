#include <il2chad/il2cpp-api.hpp>
#include <il2chad/il2cpp-structs.hpp>
#include <il2chad/metadata.hpp>
#include <unordered_map>
#include <vector>

struct MethodKey {
    std::string namespaceName;
    std::string className;
    std::string methodName;
    int argCount;

    bool operator==(const MethodKey &other) const {
        return namespaceName == other.namespaceName && className == other.className && methodName == other.methodName &&
               argCount == other.argCount;
    }
};

struct FieldKey {
    std::string namespaceName;
    std::string className;
    std::string fieldName;

    bool operator==(const FieldKey &other) const {
        return namespaceName == other.namespaceName && className == other.className && fieldName == other.fieldName;
    }
};

namespace std {
    inline void hash_combine(std::size_t &seed, std::size_t value) {
        seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    template<>
    struct hash<MethodKey> {
        size_t operator()(const MethodKey &key) const noexcept {
            size_t seed = 0;
            hash_combine(seed, hash<string>()(key.namespaceName));
            hash_combine(seed, hash<string>()(key.className));
            hash_combine(seed, hash<string>()(key.methodName));
            hash_combine(seed, hash<int>()(key.argCount));
            return seed;
        }
    };

    template<>
    struct hash<FieldKey> {
        size_t operator()(const FieldKey &key) const noexcept {
            size_t seed = 0;
            hash_combine(seed, hash<string>()(key.namespaceName));
            hash_combine(seed, hash<string>()(key.className));
            hash_combine(seed, hash<string>()(key.fieldName));
            return seed;
        }
    };
}

static std::vector<il2chad::il2cpp::Il2CppImage *> s_images;
static std::unordered_map<std::string, il2chad::il2cpp::Il2CppClass *> s_classes;
static std::unordered_map<MethodKey, void *> s_methods;
static std::unordered_map<FieldKey, std::size_t> s_fields;

static bool load_image(const char *name) {
    auto domain = il2chad::il2cpp::il2cpp_domain_get();
    auto assembly = domain ? il2chad::il2cpp::il2cpp_domain_assembly_open(domain, name) : nullptr;
    auto image = assembly ? il2chad::il2cpp::il2cpp_assembly_get_image(assembly) : nullptr;

    if (image != nullptr) {
        s_images.push_back(image);
        return true;
    }
    return false;
}

static bool index_class(const std::string &namespace_name, const std::string &class_name) {
    il2chad::il2cpp::Il2CppClass *klass = nullptr;

    for (auto *image: s_images) {
        klass = il2chad::il2cpp::il2cpp_class_from_name(image, namespace_name.c_str(), class_name.c_str());
        if (klass)
            break;
    }

    if (!klass)
        return false;

    s_classes[class_name] = klass;

    // index methods
    void *iter = nullptr;
    const il2chad::il2cpp::MethodInfo *method = nullptr;

    while ((method = il2chad::il2cpp::il2cpp_class_get_methods(klass, &iter)) != nullptr) {
        const char *methodName = il2chad::il2cpp::il2cpp_method_get_name(method);
        int argCount = il2chad::il2cpp::il2cpp_method_get_param_count(method);
        s_methods[{namespace_name, class_name, methodName, argCount}] = method->methodPointer;
        MethodKey fallbackKey{namespace_name, class_name, methodName, -1};
        if (!s_methods.contains(fallbackKey)) {
            s_methods[fallbackKey] = method->methodPointer;
        }
    }

    // index fields
    iter = nullptr;
    const il2chad::il2cpp::FieldInfo *field = nullptr;

    while ((field = il2chad::il2cpp::il2cpp_class_get_fields(klass, &iter)) != nullptr) {
        const char *fieldName = il2chad::il2cpp::il2cpp_field_get_name(field);
        auto fieldOffset = il2chad::il2cpp::il2cpp_field_get_offset(field);
        s_fields[{namespace_name, class_name, fieldName}] = fieldOffset;
    }

    return true;
}

bool il2chad::metadata::initialize(std::initializer_list<const char *> assemblies) {
    for (auto assembly: assemblies) {
        if (!load_image(assembly)) {
            printf("Failed to load assembly %s\n", assembly);
            return false;
        }
    }
    return true;
}

void *il2chad::metadata::get_method_address(const std::string &namespace_name, const std::string &class_name,
                                            const std::string &method_name, int argCount) {
    if (!s_classes.contains(class_name)) {
        index_class(namespace_name, class_name);
    }
    auto it = s_methods.find({namespace_name, class_name, method_name, argCount});
    if (it != s_methods.end()) {
        return it->second;
    }
    return 0;
}

std::size_t il2chad::metadata::get_field_offset(const std::string &namespace_name, const std::string &class_name,
                                                const std::string &field_name) {
    if (!s_classes.contains(class_name)) {
        index_class(namespace_name, class_name);
    }
    auto it = s_fields.find({namespace_name, class_name, field_name});
    if (it != s_fields.end()) {
        return it->second;
    }
    return 0;
}
