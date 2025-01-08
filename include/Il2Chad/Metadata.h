#pragma once

namespace Il2Chad::Metadata {
    /**
     * Initializes metadata cache
     */
    void initialize();

    /**
     *
     * @param className Case-sensitive class name
     * @param fieldName Case-sensitive field name
     * @return Field offset or SIZE_MAX if not found
     */
    size_t getFieldOffset(const char *className, const char *fieldName);

    struct Property {
        void *getter;
        void *setter;
    };

    Property *getProperty(const char *className, const char *propertyName);

    /**
     * @param className Case-sensitive class name
     * @param methodName Case-sensitive method name
     * @return Method pointer or nullptr if not found
     */
    void *getMethod(const char *className, const char *methodName);
}
