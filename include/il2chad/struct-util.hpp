#pragma once
#include <il2chad/il2cpp-api.hpp>
#include <il2chad/il2cpp-structs.hpp>

// handles optional obfuscated name
#define IL2CPP_FIELD_NAME(name, ...) (sizeof(#__VA_ARGS__) > 1 ? #__VA_ARGS__ : #name)

#define IL2CPP_FIELD(type, name, ...)                                                                                  \
    type Get##name() const {                                                                                           \
        static il2chad::il2cpp::Il2CppClass *klass = nullptr;                                                          \
        static size_t offset = 0;                                                                                      \
                                                                                                                       \
        if (!klass) {                                                                                                  \
            klass = il2chad::il2cpp::il2cpp_object_get_class((il2chad::il2cpp::Il2CppObject *) this);                  \
            auto field =                                                                                               \
                    il2chad::il2cpp::il2cpp_class_get_field_from_name(klass, IL2CPP_FIELD_NAME(name, ##__VA_ARGS__));  \
            offset = il2chad::il2cpp::il2cpp_field_get_offset(field);                                                  \
        }                                                                                                              \
                                                                                                                       \
        return *reinterpret_cast<type *>((char *) this + offset);                                                      \
    }                                                                                                                  \
                                                                                                                       \
    void Set##name(type value) {                                                                                       \
        static il2chad::il2cpp::Il2CppClass *klass = nullptr;                                                          \
        static size_t offset = 0;                                                                                      \
                                                                                                                       \
        if (!klass) {                                                                                                  \
            klass = il2chad::il2cpp::il2cpp_object_get_class((il2chad::il2cpp::Il2CppObject *) this);                  \
            auto field =                                                                                               \
                    il2chad::il2cpp::il2cpp_class_get_field_from_name(klass, IL2CPP_FIELD_NAME(name, ##__VA_ARGS__));  \
            offset = il2chad::il2cpp::il2cpp_field_get_offset(field);                                                  \
        }                                                                                                              \
                                                                                                                       \
        *reinterpret_cast<type *>(reinterpret_cast<char *>(this) + offset) = value;                                    \
    }

#define IL2CPP_PROPERTY(type, name, ...)                                                                               \
    type Get##name() const {                                                                                           \
        using GetterFn = type (*)(decltype(this), void *);                                                             \
        static il2chad::il2cpp::Il2CppClass *klass = nullptr;                                                          \
        static GetterFn getter = nullptr;                                                                              \
                                                                                                                       \
        if (!klass) {                                                                                                  \
            klass = il2chad::il2cpp::il2cpp_object_get_class((il2chad::il2cpp::Il2CppObject *) this);                  \
            auto *prop =                                                                                               \
                    const_cast<il2chad::il2cpp::PropertyInfo *>(il2chad::il2cpp::il2cpp_class_get_property_from_name(  \
                            klass, IL2CPP_FIELD_NAME(name, ##__VA_ARGS__)));                                           \
            auto *mi = il2chad::il2cpp::il2cpp_property_get_get_method(prop);                                          \
            getter = reinterpret_cast<GetterFn>(mi->methodPointer);                                                    \
        }                                                                                                              \
        return getter(this, nullptr);                                                                                  \
    }                                                                                                                  \
    void Set##name(type value) {                                                                                       \
        using SetterFn = void (*)(decltype(this), type, void *);                                                       \
        static il2chad::il2cpp::Il2CppClass *klass = nullptr;                                                          \
        static SetterFn setter = nullptr;                                                                              \
                                                                                                                       \
        if (!klass) {                                                                                                  \
            klass = il2chad::il2cpp::il2cpp_object_get_class((il2chad::il2cpp::Il2CppObject *) this);                  \
            auto *prop =                                                                                               \
                    const_cast<il2chad::il2cpp::PropertyInfo *>(il2chad::il2cpp::il2cpp_class_get_property_from_name(  \
                            klass, IL2CPP_FIELD_NAME(name, ##__VA_ARGS__)));                                           \
            auto *mi = il2chad::il2cpp::il2cpp_property_get_set_method(prop);                                          \
            setter = reinterpret_cast<SetterFn>(mi->methodPointer);                                                    \
        }                                                                                                              \
        setter(this, value, nullptr);                                                                                  \
    }
