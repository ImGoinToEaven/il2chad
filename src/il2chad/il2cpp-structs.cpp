#include <il2chad/il2cpp-structs.hpp>
#include <string>
#include "il2chad/il2cpp-api.hpp"

const char *il2chad::il2cpp::Il2CppString::Unbox() {
    thread_local std::string buffer;
    buffer.clear();
    auto *chars = il2cpp_string_chars(this);
    auto length = il2cpp_string_length(this);
    for (int i = 0; i < length; ++i)
        buffer += static_cast<char>(chars[i]);
    return buffer.c_str();
}
