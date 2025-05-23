#include "Window.hpp"
#include <GLFW/glfw3.h>

Window::Window(WindowHints hints)
    : WindowBase(std::move(hints)), timer(glfwGetTime) {}

void Window::onInit() {}
void Window::onUpdate(double) {}
void Window::processInput(double dt) {}
void Window::onRender() {}
void Window::onInput() {}
void Window::onResize(int width, int height) {}

void Window::run() {
    onInit();
    show();
    while (!shouldClose()) {
        pollEvents();
        onInput();


        GameTime gametime = timer.tick();
        onUpdate(gametime.delta);
        processInput(gametime.delta);

        onRender();
        swapBuffers();
    }
}
