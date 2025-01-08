#pragma once

namespace Il2Chad::Utils {
    void getValue(void *instance, const char *fieldName);
    void setValue(void *instance, const char *fieldName, void *value);
    void invoke(void *instance, const char *methodName, void *args);
}
