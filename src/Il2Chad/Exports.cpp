#include <Il2Chad/Exports.h>
#include <Windows.h>
#include <iostream>

bool Il2Chad::Exports::initialize(const char *assemblyName)
{
	HMODULE module = nullptr;
	while (module = GetModuleHandleA(assemblyName), !module)
	{
		printf("Il2Chad: Waiting for %s\n", assemblyName);
		Sleep(1000);
	}

	void *mainExport = nullptr;
	while (mainExport = (void *)GetProcAddress(module, "mono_domain_get_assemblies_iter"), !mainExport)
	{
		printf("Il2Chad: Waiting for mono_domain_get_assemblies_iter\n");
		Sleep(1000);
	}

	printf("Il2Chad: Main export found. Resolving exports\n");

	for (const auto &export_ : Internal::exports)
	{
		*export_.functionPtr = static_cast<void *>(GetProcAddress(module, export_.name));
		printf("Il2Chad: Export %s: %p\n", export_.name, *export_.functionPtr);
	}

	printf("Again, il2cpp_class_get_fields = %p\n", il2cpp_class_get_fields);

	return true;
}