#pragma once

class Il2CppObject;
class Il2CppClass;

namespace Il2Chad::Utils {
    Il2CppClass *get_class(Il2CppObject *object);

    const char *get_class_name(Il2CppClass *klass);

    /**
     * Warning: You are responsible for calling the object's constructor
     * @param klass Class to instantiate
     * @return A new instance of the class
     */
    Il2CppObject *create_object(Il2CppClass *klass);

    Il2CppObject *create_string(const char *str);

    void invoke(Il2CppObject *object, const char *method_name, void **params);

    void invoke_convert_args(Il2CppObject *object, const char *method_name, void **params, int param_count);
}
