cmake_minimum_required(VERSION 3.14)
project(WinterPlatformer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add glad.c explicitly to sources
list(APPEND SOURCES src/glad.c)

add_executable(WinterPlatformer ${SOURCES})

target_include_directories(WinterPlatformer PRIVATE src src/glad)

target_link_libraries(WinterPlatformer PRIVATE OpenGL::GL glfw)
