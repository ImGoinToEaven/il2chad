#include "Il2Chad/Utils.h"
#include "Imports.h"

Il2CppClass *Il2Chad::Utils::get_class(Il2CppObject *object) {
    return Imports::il2cpp_object_get_class(object);
}

const char *Il2Chad::Utils::get_class_name(Il2CppClass *klass) {
    return Imports::il2cpp_class_get_name(klass);
}

Il2CppObject *Il2Chad::Utils::create_object(Il2CppClass *klass) {
    return Imports::il2cpp_object_new(klass);
}

void Il2Chad::Utils::invoke(Il2CppObject *object, const char *method_name, void **params) {
    auto klass = get_class(object);
    auto method = Imports::il2cpp_class_get_method_from_name(klass, method_name, -1);
    if (method) {
        Imports::il2cpp_runtime_invoke(method, object, params, nullptr);
    }
}

void Il2Chad::Utils::invoke_convert_args(Il2CppObject *object, const char *method_name, void **params, int param_count) {
    auto klass = get_class(object);
    auto method = Imports::il2cpp_class_get_method_from_name(klass, method_name, param_count);
    if (method) {
        Imports::il2cpp_runtime_invoke_convert_args(method, object, (Il2CppObject **)params, param_count, nullptr);
    }
}
