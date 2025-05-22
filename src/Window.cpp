#include "Window.hpp"

Window::Window(WindowHints hints)
    : WindowBase(std::move(hints)), timer(glfwGetTime) {}

void Window::onInit() {}
void Window::onUpdate(double) {}
void Window::onRender() {}
void Window::onInput() {}

void Window::run() {
    onInit();
    show();
    while (!shouldClose()) {
        pollEvents();
        onInput();

        GameTime gametime = timer.tick();
        onUpdate(gametime.delta);

        onRender();
        swapBuffers();
    }
}
