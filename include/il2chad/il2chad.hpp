#pragma once
#include <initializer_list>
#include "metadata.hpp"
#include "unity.hpp"

namespace il2chad {
    bool initialize(std::initializer_list<const char *> assemblies);
}
