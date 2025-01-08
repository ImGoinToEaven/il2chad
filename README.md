# Il2Chad

Il2Chad is a minimalist library for interacting with Il2Cpp at runtime

## Installation

Il2Chad was designed for use with CMakes FetchContent module.
To use Il2Chad in your project, add the following to your **CMakeLists.txt**

```cmake
FetchContent_Declare(
        Il2Chad
        GIT_REPOSITORY https://github.com/ImGoinToEaven/Il2Chad.git
        GIT_TAG master
)
FetchContent_MakeAvailable(Il2Chad)
target_link_libraries(YourProject PRIVATE Il2Chad)
```

## Usage

```cpp
#include <Il2Chad/Il2Chad.hpp>

int main() {
    Il2Chad::initialize();
    Il2Chad::Metadata::getFieldOffset("UnityEngine", "GameObject", "m_CachedPtr");
    Il2Chad::Metadata::getMethodPointer("UnityEngine", "GameObject", ".ctor", 0);
    Il2Chad::Metadata::getProperty("UnityEngine", "GameObject", "name");
}
```