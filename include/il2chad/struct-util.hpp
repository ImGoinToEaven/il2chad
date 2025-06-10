#pragma once
#include <il2chad/il2cpp-api.hpp>
#include <il2chad/il2cpp-structs.hpp>

#define IL2CPP_FIELD(type, name, ...)                                                                                  \
    type get_##name() const {                                                                                          \
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
    void set_##name(type value) {                                                                                      \
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

// handles optional obfuscated name
#define IL2CPP_FIELD_NAME(name, ...) (sizeof(#__VA_ARGS__) > 1 ? #__VA_ARGS__ : #name)
