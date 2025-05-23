#pragma once

#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <tuple>

class WindowHints {
public:
  WindowHints(std::string title, std::map<int, int> flags,
              const unsigned int height, const unsigned int width);
  static WindowHints Default();

  std::string title;
  std::map<int, int> flags;
  int width;
  int height;
};

class WindowBase {
public:
  const WindowHints Hints;
  explicit WindowBase(WindowHints hints = WindowHints::Default());

  GLFWwindow *getHandle();

  void pollEvents();
  void swapBuffers();
  void setShouldClose(bool value);
  void setCursorMode(GLenum mode);
  void setWindowSize(int x, int y);
  void show();
  void hide();
  int getKey(int key);
  int getMouseButton(int button);
  GLenum getCursorMode();
  std::tuple<double, double> getCursorPos();
  std::tuple<int, int> getWindowSize();
  bool shouldClose();

  virtual ~WindowBase();

protected:
  GLFWwindow *handle;
};
