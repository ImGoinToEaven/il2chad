#pragma once

class Il2CppObject;
struct Il2CppDomain;
struct Il2CppAssembly;
struct Il2CppImage;
class Il2CppClass;
class Il2CppException;
class Il2CppType;

struct MethodInfo {
    void *methodPointer;
};

struct FieldInfo;
struct PropertyInfo;

struct Il2CppAssembly {
    Il2CppImage *image;
};
