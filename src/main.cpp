#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Window {
public:
  Window(int width, int height, string title,
         std::map<int, int> flags = {
             {GLFW_CONTEXT_VERSION_MAJOR, 4},
             {GLFW_CONTEXT_VERSION_MINOR, 6},
             {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
             {GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE},
             {GLFW_VISIBLE, GLFW_FALSE}}) {

    if (!glfwInit()) {
      std::cerr << "GLFW initialization failed!" << std::endl;
      throw std::runtime_error("glfwInit failed");
    }

    for (const auto &pair : flags) {
      glfwWindowHint(pair.first, pair.second);
    }

    handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!handle) {
      glfwTerminate();
      std::cerr << "Failed to create GLFW Window!" << std::endl;
      throw std::runtime_error("glfwCreateWindow failed");
    }

    glfwMakeContextCurrent(handle);
  }

  GLFWwindow *getHandle() { return handle; }

  ~Window() {
    glfwDestroyWindow(handle);
    glfwTerminate();
  }

private:
  GLFWwindow *handle;
};

int main() {
  Window w = Window(800, 600, "GLFW Window");
  return 0;
}
