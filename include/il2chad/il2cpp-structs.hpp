#pragma once
#include <string>
#include "il2cpp-api.hpp"

namespace il2chad::il2cpp {
    class Il2CppDomain;
    class Il2CppAssembly;
    class Il2CppImage;
    class Il2CppClass;

    struct MethodInfo {
        void (*methodPointer)();
    };

    class Il2CppObject {
    public:
        template<typename TReturn, typename... TArgs>
        TReturn CallMethod(const char *name, TArgs... args) {
            static auto klass = il2cpp_object_get_class(this);
            auto method = il2cpp_class_get_method_from_name(klass, name, sizeof...(args));
            if (method) {
                using MethodFn = TReturn (*)(Il2CppObject *, TArgs..., void *);
                auto methodFn = reinterpret_cast<MethodFn>(method->methodPointer);
                return methodFn(this, args..., nullptr);
            }
            if constexpr (!std::is_void_v<TReturn>)
                return {};
        }
    };

    class Il2CppString : public Il2CppObject {
    public:
        std::string Unbox();
    };


    struct FieldInfo;
    struct PropertyInfo;
}
