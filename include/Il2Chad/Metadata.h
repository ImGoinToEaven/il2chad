#pragma once
#include "Structs.h"

namespace Il2Chad::Metadata
{
	struct Property
	{
		void *getter;
		void *setter;
	};

	bool initialize(const char *assemblyName);
	Il2CppClass *getClass(const char *className);
	void *getMethod(const char *className, const char *methodName);
	Property *getProperty(const char *className, const char *propertyName);
	size_t getFieldOffset(const char *className, const char *fieldName);
}