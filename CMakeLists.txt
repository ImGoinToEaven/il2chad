cmake_minimum_required(VERSION 3.30)
project(il2chad)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE IL2CHAD_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(il2chad STATIC ${IL2CHAD_SOURCES})

target_include_directories(il2chad
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
