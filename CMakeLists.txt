cmake_minimum_required(VERSION 3.30)
project(Il2Chad)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

add_library(Il2Chad STATIC ${SOURCES})

target_include_directories(Il2Chad
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS Il2Chad
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
