#include <Il2Chad/Exports.h>
#include <Il2Chad/Il2Chad.h>
#include <Il2Chad/Metadata.h>

bool Il2Chad::initialize(const char *assemblyName)
{
	return Exports::initialize(assemblyName) && Metadata::initialize(assemblyName);
}