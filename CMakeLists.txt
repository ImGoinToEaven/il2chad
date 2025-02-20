cmake_minimum_required(VERSION 3.30)
project(Il2Chad)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

add_library(Il2Chad STATIC ${SOURCES})
set_target_properties(Il2Chad PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Il2Chad
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)


# Test shared library
add_library(Il2ChadTest SHARED ${SOURCES} "test/Main.cpp")
set_target_properties(Il2ChadTest PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Il2ChadTest
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)