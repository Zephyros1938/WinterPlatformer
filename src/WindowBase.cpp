#include "WindowBase.hpp"
#include <GLFW/glfw3.h>

WindowHints::WindowHints(std::string title, std::map<int, int> flags, const unsigned int height, const unsigned int width)
    : title(std::move(title)), flags(std::move(flags)), width(width), height(height) {}

WindowHints WindowHints::Default() {
    return WindowHints("GLFW Window",
                       {
                           {GLFW_CONTEXT_VERSION_MAJOR, 4},
                           {GLFW_CONTEXT_VERSION_MINOR, 6},
                           {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
                           {GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE},
                           {GLFW_VISIBLE, GLFW_FALSE}
                       },
                       720, 1080);
}



WindowBase::WindowBase(const WindowHints hints) : Hints(hints) {

    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        throw std::runtime_error("glfwInit failed");
    }

    for (const auto& pair : hints.flags) {
        glfwWindowHint(pair.first, pair.second);
    }

    handle = glfwCreateWindow(hints.width, hints.height, hints.title.c_str(), nullptr, nullptr);
    if (!handle) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW Window!" << std::endl;
        throw std::runtime_error("glfwCreateWindow failed");
    }

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        throw std::runtime_error("gladLoadGLLoader failed");
    }
}

GLFWwindow* WindowBase::getHandle() {
    return handle;
}

void WindowBase::pollEvents() {
    glfwPollEvents();
}

void WindowBase::swapBuffers() {
    glfwSwapBuffers(handle);
}

void WindowBase::setShouldClose(bool value) {
    glfwSetWindowShouldClose(handle, value);
}

void WindowBase::setCursorMode(GLenum mode) {
    glfwSetInputMode(handle, GLFW_CURSOR, mode);
}

void WindowBase::setWindowSize(int x, int y) {
    glfwSetWindowSize(handle, x, y);
}

void WindowBase::show() {
    glfwShowWindow(handle);
}

void WindowBase::hide() {
    glfwHideWindow(handle);
}

int WindowBase::getKey(int key) {
    return glfwGetKey(handle, key);
}

int WindowBase::getMouseButton(int button) {
    return glfwGetMouseButton(handle, button);
}

GLenum WindowBase::getCursorMode() {
    return glfwGetInputMode(handle, GLFW_CURSOR);
}

std::tuple<double, double> WindowBase::getCursorPos() {
    double xpos = 0, ypos = 0;
    glfwGetCursorPos(handle, &xpos, &ypos);
    return {xpos, ypos};
}

std::tuple<int, int> WindowBase::getWindowSize() {
    int width = 0, height = 0;
    glfwGetWindowSize(handle, &width, &height);
    return {width, height};
}

bool WindowBase::shouldClose() {
    return glfwWindowShouldClose(handle);
}

WindowBase::~WindowBase() {
    glfwDestroyWindow(handle);
    glfwTerminate();
}
