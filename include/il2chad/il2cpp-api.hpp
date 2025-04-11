#pragma once
#include <Windows.h>
#include "il2cpp-structs.hpp"

#define IL2CPP_API(ret, name, ...)                                                                                     \
    inline auto name =                                                                                                 \
            reinterpret_cast<ret (*)(__VA_ARGS__)>(GetProcAddress(GetModuleHandle("GameAssembly.dll"), #name));

namespace il2chad::il2cpp {
    IL2CPP_API(Il2CppDomain *, il2cpp_domain_get)
    IL2CPP_API(Il2CppAssembly *, il2cpp_domain_assembly_open, Il2CppDomain *domain, const char *name)
    IL2CPP_API(Il2CppImage *, il2cpp_assembly_get_image, Il2CppAssembly const *assembly)

    IL2CPP_API(Il2CppClass *, il2cpp_class_from_name, Il2CppImage const *image, const char *namespace_name,
               const char *class_name)
    IL2CPP_API(MethodInfo const *, il2cpp_class_get_methods, Il2CppClass *klass, void **iter)
    IL2CPP_API(FieldInfo const *, il2cpp_class_get_fields, Il2CppClass *klass, void **iter)
    IL2CPP_API(FieldInfo const *, il2cpp_class_get_field_from_name, Il2CppClass *klass, const char *name);

    IL2CPP_API(Il2CppClass *, il2cpp_object_get_class, Il2CppObject *obj);

    IL2CPP_API(char const *, il2cpp_method_get_name, MethodInfo const *method)
    IL2CPP_API(int, il2cpp_method_get_param_count, const MethodInfo *method)

    IL2CPP_API(char const *, il2cpp_field_get_name, FieldInfo const *field)
    IL2CPP_API(size_t, il2cpp_field_get_offset, FieldInfo const *field)

    IL2CPP_API(Il2CppString *, il2cpp_string_new, const char *str)
    IL2CPP_API(Il2CppString *, il2cpp_string_chars, Il2CppString *str)
}

#undef IL2CPP_API
