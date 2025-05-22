#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include <tuple>
#include <iostream>
#include <stdexcept>

class WindowHints {
public:
    WindowHints(std::string title, std::map<int, int> flags, int height, int width);
    static WindowHints Default();

    std::string title;
    std::map<int, int> flags;
    int width;
    int height;
};

class WindowBase {
public:
    explicit WindowBase(WindowHints hints = WindowHints::Default());

    GLFWwindow* getHandle();

    void pollEvents();
    void swapBuffers();
    void setShouldClose(bool value);
    void setCursorMode(GLenum mode);
    void setWindowSize(int x, int y);
    void show();
    void hide();
    int getKey(int key);
    GLenum getMouseButton(GLenum button);
    GLenum getCursorMode();
    std::tuple<double, double> getCursorPos();
    std::tuple<int, int> getWindowSize();
    bool shouldClose();

    virtual ~WindowBase();

protected:
    GLFWwindow* handle;
};
