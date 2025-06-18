#pragma once
#include <Windows.h>
#include <cstdint>

#define IL2CPP_API(ret, name, ...)                                                                                     \
    inline auto name =                                                                                                 \
            reinterpret_cast<ret (*)(__VA_ARGS__)>(GetProcAddress(GetModuleHandle("GameAssembly.dll"), #name));

namespace il2chad::il2cpp {
    class Il2CppDomain;
    class Il2CppAssembly;
    class Il2CppImage;
    class Il2CppClass;
    class MethodInfo;
    class FieldInfo;
    class PropertyInfo;
    class Il2CppObject;
    class Il2CppString;

    IL2CPP_API(Il2CppDomain *, il2cpp_domain_get)
    IL2CPP_API(Il2CppAssembly *, il2cpp_domain_assembly_open, Il2CppDomain *domain, const char *name)
    IL2CPP_API(Il2CppImage *, il2cpp_assembly_get_image, Il2CppAssembly const *assembly)


    IL2CPP_API(size_t, il2cpp_image_get_class_count, const Il2CppImage *image);
    IL2CPP_API(const Il2CppClass *, il2cpp_image_get_class, const Il2CppImage *image, size_t index);

    IL2CPP_API(Il2CppClass *, il2cpp_class_from_name, Il2CppImage const *image, const char *namespace_name,
               const char *class_name)
    IL2CPP_API(MethodInfo const *, il2cpp_class_get_methods, Il2CppClass *klass, void **iter)
    IL2CPP_API(FieldInfo const *, il2cpp_class_get_fields, Il2CppClass *klass, void **iter)
    IL2CPP_API(FieldInfo const *, il2cpp_class_get_field_from_name, Il2CppClass *klass, const char *name);
    IL2CPP_API(const MethodInfo *, il2cpp_class_get_method_from_name, Il2CppClass *klass, const char *name,
               int argsCount);
    IL2CPP_API(const PropertyInfo*, il2cpp_class_get_property_from_name, Il2CppClass * klass, const char *name);
    IL2CPP_API(const char *, il2cpp_class_get_name, Il2CppClass *klass);
    IL2CPP_API(const char *, il2cpp_class_get_namespace, Il2CppClass *klass);

    IL2CPP_API(Il2CppClass *, il2cpp_object_get_class, Il2CppObject *obj);
    IL2CPP_API(Il2CppObject *, il2cpp_object_new, Il2CppClass *klass);
    IL2CPP_API(void, il2cpp_runtime_object_init, Il2CppObject *obj);

    IL2CPP_API(char const *, il2cpp_method_get_name, MethodInfo const *method)
    IL2CPP_API(int, il2cpp_method_get_param_count, const MethodInfo *method)

    IL2CPP_API(const MethodInfo*, il2cpp_property_get_get_method, PropertyInfo * prop);
    IL2CPP_API(const MethodInfo*, il2cpp_property_get_set_method, PropertyInfo * prop);
    IL2CPP_API(const char*, il2cpp_property_get_name, PropertyInfo * prop);

    IL2CPP_API(char const *, il2cpp_field_get_name, FieldInfo const *field)
    IL2CPP_API(size_t, il2cpp_field_get_offset, FieldInfo const *field)

    IL2CPP_API(Il2CppString *, il2cpp_string_new, const char *str)
    IL2CPP_API(const wchar_t *, il2cpp_string_chars, Il2CppString *str)
    IL2CPP_API(int32_t, il2cpp_string_length, Il2CppString *str)
}

#undef IL2CPP_API
