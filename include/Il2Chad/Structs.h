#pragma once
#include <cstdint>

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

struct PropertyInfo
{
	Il2CppClass *parent;
	const char *name;
	const MethodInfo *get;
	const MethodInfo *set;
	uint32_t attrs;
	uint32_t token;
};


struct Il2CppAssembly {
    Il2CppImage *image;
};
