#pragma once
#include <cstdint>
#include <string>

namespace il2chad::metadata {
    bool initialize(std::initializer_list<const char *> assemblies);
    void* get_method_address(const std::string &namespace_name, const std::string &class_name,
                                      const std::string &method_name, int argCount = -1);
    std::size_t get_field_offset(const std::string &namespace_name, const std::string &class_name,
                                 const std::string &field_name);
}
