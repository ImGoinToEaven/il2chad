cmake_minimum_required(VERSION 3.30)
project(il2chad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Automatically grab all sources
file(GLOB_RECURSE IL2CHAD_SOURCES CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

# Define the static lib
add_library(il2chad STATIC ${IL2CHAD_SOURCES})

# Include the headers (include/il2chad/*.hpp)
target_include_directories(il2chad
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Alias for FetchContent / find_package use
add_library(il2chad::il2chad ALIAS il2chad)

# Test lib
add_library(il2chad_test SHARED src/test_lib/main.cpp)
target_link_libraries(il2chad_test il2chad)
