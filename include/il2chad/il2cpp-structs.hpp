#pragma once

namespace il2chad::il2cpp {
    class Il2CppDomain;
    class Il2CppAssembly;
    class Il2CppImage;
    class Il2CppClass;
    class Il2CppString;

    struct MethodInfo {
        void (*methodPointer)();
    };

    struct FieldInfo;

}
