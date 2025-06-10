#pragma once
#include <string>

namespace il2chad::il2cpp {
    class Il2CppDomain;
    class Il2CppAssembly;
    class Il2CppImage;
    class Il2CppClass;
    class Il2CppObject {};

    class Il2CppString : public Il2CppObject {
    public:
        std::string Unbox();
    };

    struct MethodInfo {
        void (*methodPointer)();
    };

    struct FieldInfo;
}
