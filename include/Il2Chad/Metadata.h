#pragma once

class Il2CppClass;

namespace Il2Chad::Metadata {
    /**
     * Initializes metadata cache
     */
    void initialize();

    /**
     * @param class_name Case-sensitive, fully qualified class name
     * @return Class pointer or nullptr if not found
     */
    Il2CppClass *get_class(const char *class_name);

    /**
     * @param class_name Case-sensitive class name
     * @param field_name Case-sensitive field name
     * @return Field offset or SIZE_MAX if not found
     */
    size_t get_field_offset(const char *class_name, const char *field_name);

    struct Property {
        void *getter;
        void *setter;
    };

    Property *get_property(const char *class_name, const char *property_name);

    /**
     * @param class_name Case-sensitive class name
     * @param method_name Case-sensitive method name
     * @return Method pointer or nullptr if not found
     */
    void *get_method(const char *class_name, const char *method_name);
}
