#include "Window.hpp"
#include <GLFW/glfw3.h>

// - Constructor - //
Window::Window(WindowHints hints)
    : WindowBase(std::move(hints)), timer(glfwGetTime) {}

// - Virtual Methods - //
void Window::onInit() {}
void Window::onUpdate(GameTime gt) {}
void Window::processInput(GameTime gt) {}
void Window::onRender() {}
void Window::onInput() {}
void Window::onResize(int width, int height) {}

// - Callbacks - //
void Window::setCallbacks() {
  glfwSetWindowUserPointer(handle, this);
  glfwSetFramebufferSizeCallback(handle, framebuffer_size_callback);
}

void Window::framebuffer_size_callback(GLFWwindow *win, int width, int height) {
  Window *self = static_cast<Window *>(glfwGetWindowUserPointer(win));
  if (self) {
    self->onResize(width, height);
  }
}

// - Run - //
void Window::run() {
  onInit();
  setCallbacks();
  show();
  while (!shouldClose()) {
    pollEvents();
    onInput();

    GameTime gametime = timer.tick();
    processInput(gametime);
    onUpdate(gametime);

    onRender();
    swapBuffers();
  }
}
