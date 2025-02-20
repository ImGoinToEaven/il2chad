#include <Il2Chad/Exports.h>
#include <Il2Chad/Metadata.h>
#include <map>
#include <string>

using namespace Il2Chad::Exports;
using StringPair = std::pair<std::string, std::string>;
static std::map<std::string, Il2CppClass *> classes;
static std::map<StringPair, size_t> fieldOffsets;
static std::map<StringPair, Il2Chad::Metadata::Property*> properties;
static std::map<StringPair, void *> methods;

// This was added to avoid class name collisions, but it might be nice to have a flag to disable this
static std::string getClassFQN(Il2CppClass *klass)
{
	auto klassName = il2cpp_class_get_name(klass);
	auto namespaceName = il2cpp_class_get_namespace(klass);
	if (namespaceName && namespaceName[0] != '\0')
	{
		return std::string(namespaceName) + "." + klassName;
	}
	return klassName;
}

static void indexClass(Il2CppClass* klass)
{
	auto klassName = getClassFQN(klass);
	classes[klassName] = klass;

	// index fields
	void *iter = nullptr;
	const FieldInfo *field = nullptr;

	while ((field = il2cpp_class_get_fields(klass, &iter)) != nullptr) {
		const char *fieldName = il2cpp_field_get_name(field);
		auto fieldOffset = il2cpp_field_get_offset(field);
		fieldOffsets[{klassName, fieldName}] = fieldOffset;
	}

	// index properties
	iter = nullptr;
	const PropertyInfo *property = nullptr;

	while ((property = il2cpp_class_get_properties(klass, &iter)) != nullptr) {
		const char *propertyName = il2cpp_property_get_name(property);
		auto getter = il2cpp_property_get_get_method(property);
		auto setter = il2cpp_property_get_set_method(property);
		properties[{klassName, propertyName}] = new Il2Chad::Metadata::Property{
			getter ? getter->methodPointer : nullptr,
			setter ? setter->methodPointer : nullptr
		};
	}

	// index methods
	iter = nullptr;
	const MethodInfo *method = nullptr;

	while ((method = il2cpp_class_get_methods(klass, &iter)) != nullptr) {
		const char *methodName = il2cpp_method_get_name(method);
		methods[{klassName, methodName}] = method->methodPointer;
	}
}

static void indexIl2CppAssemblies(Il2CppDomain *domain) {
	// todo
}

static void indexMonoAssemblies(Il2CppDomain *domain) {
	void *iter = nullptr;
	const Il2CppAssembly *assembly = nullptr;

	while ((assembly = mono_domain_get_assemblies_iter(domain, &iter)) != nullptr) {
		auto image = assembly->image;
		auto class_count = il2cpp_image_get_class_count(image);
		for (size_t j = 0; j < class_count; ++j) {
			auto klass = il2cpp_image_get_class(image, j);
			indexClass(klass);
		}
	}
}

bool Il2Chad::Metadata::initialize(const char *assemblyName)
{
	auto domain = il2cpp_domain_get();

	if (mono_domain_get_assemblies_iter) {
		indexMonoAssemblies(domain);
	} else {
		indexIl2CppAssemblies(domain);
	}

	return true;
}

Il2CppClass *Il2Chad::Metadata::getClass(const char *className)
{
	return classes[className];
}

void *Il2Chad::Metadata::getMethod(const char *className, const char *methodName)
{
	return methods[{className, methodName}];
}

Il2Chad::Metadata::Property*Il2Chad::Metadata::getProperty(const char *className, const char *propertyName)
{
	return properties[{className, propertyName}];
}

size_t Il2Chad::Metadata::getFieldOffset(const char *className, const char *fieldName)
{
	return fieldOffsets[{className, fieldName}];
}