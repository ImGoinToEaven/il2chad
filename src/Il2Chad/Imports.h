#pragma once
#include <Windows.h>
#include "Types.h"

#define IL2CPP_API(ret, name, ...)      \
typedef ret (*name##_t)(__VA_ARGS__); \
inline name##_t name = (name##_t)GetProcAddress(module, #name);

namespace Il2Chad::Imports {
    static inline HMODULE module = GetModuleHandle("GameAssembly.dll");
    IL2CPP_API(Il2CppDomain*, il2cpp_domain_get)
    IL2CPP_API(Il2CppImage*, il2cpp_assembly_get_image, Il2CppAssembly const* assembly)
    // Some games seem to export mono_domain_get_assemblies_iter instead of il2cpp_domain_get_assemblies
    // This whole thing is just a quality of life measure so it may just be easier to have people specify assembly names manually
    IL2CPP_API(Il2CppAssembly const**, il2cpp_domain_get_assemblies, Il2CppDomain const* domain, size_t* size)
    IL2CPP_API(Il2CppAssembly*, mono_domain_get_assemblies_iter, void* domain, void** iter)
    IL2CPP_API(size_t, il2cpp_image_get_class_count, Il2CppImage const* image)
    IL2CPP_API(Il2CppClass*, il2cpp_image_get_class, Il2CppImage const* image, size_t index)

    IL2CPP_API(char const*, il2cpp_class_get_name, Il2CppClass* klass)
    IL2CPP_API(char const*, il2cpp_class_get_namespace, Il2CppClass* klass)
    IL2CPP_API(FieldInfo const*, il2cpp_class_get_fields, Il2CppClass* klass, void** iter)
    IL2CPP_API(PropertyInfo const*, il2cpp_class_get_properties, Il2CppClass* klass, void** iter)
    IL2CPP_API(MethodInfo const*, il2cpp_class_get_methods, Il2CppClass* klass, void** iter)

    IL2CPP_API(char const*, il2cpp_field_get_name, FieldInfo const* field)
    IL2CPP_API(size_t, il2cpp_field_get_offset, FieldInfo const* field)

    IL2CPP_API(char const*, il2cpp_property_get_name, PropertyInfo const* prop)
    IL2CPP_API(MethodInfo const*, il2cpp_property_get_get_method, PropertyInfo const* prop)
    IL2CPP_API(MethodInfo const*, il2cpp_property_get_set_method, PropertyInfo const* prop)

    IL2CPP_API(char const*, il2cpp_method_get_name, MethodInfo const* method)

    IL2CPP_API(Il2CppClass*, il2cpp_object_get_class, Il2CppObject* obj)
    IL2CPP_API(Il2CppObject*, il2cpp_object_new, Il2CppClass* klass)
    IL2CPP_API(MethodInfo*, il2cpp_class_get_method_from_name, Il2CppClass* klass, const char* name, int arg_count)

    IL2CPP_API(Il2CppObject*, il2cpp_runtime_invoke_convert_args, MethodInfo* method, void* obj, Il2CppObject** params, int paramCount, Il2CppException** exc)
    IL2CPP_API(Il2CppObject*, il2cpp_runtime_invoke, MethodInfo* method, void* obj, void** params, Il2CppException** exc)
}

#undef IL2CPP_API
