#pragma once

struct Il2CppDomain;
struct Il2CppAssembly;
struct Il2CppImage;
struct Il2CppClass;

struct MethodInfo {
    void *methodPointer;
};

struct FieldInfo;
struct PropertyInfo;

struct Il2CppAssembly {
    Il2CppImage *image;
};
