cmake_minimum_required(VERSION 3.14)
project(WinterPlatformer)

set(CMAKE_CXX_STANDARD 17)

# GLFW & GLAD paths (you may need to update these)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(WinterPlatformer ${SOURCES})

# Includes and links
target_include_directories(WinterPlatformer PRIVATE src)
target_link_libraries(WinterPlatformer PRIVATE OpenGL::GL glfw)
