cmake_minimum_required(VERSION 3.30)
project(il2chad)

set(CMAKE_CXX_STANDARD 23)
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
add_library(il2chad STATIC ${SOURCES})

target_include_directories(il2chad PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Test target for injection, useful for checking if changes to the library are working
#add_library(il2chad_test SHARED test/Main.cpp ${SOURCES})
#target_include_directories(il2chad_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
#target_link_libraries(il2chad_test il2chad)
