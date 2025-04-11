#include <il2chad/il2chad.hpp>
#include <vector>


bool il2chad::initialize(std::initializer_list<const char *> assemblies) {
    metadata::initialize(assemblies);
    return true;
}
