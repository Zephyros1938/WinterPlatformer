#pragma once

#include "Time.hpp"
#include "WindowBase.hpp"

class Window : public WindowBase {
public:
  explicit Window(WindowHints hints = WindowHints::Default());

  virtual void onInit();
  virtual void onUpdate(GameTime gt);
  virtual void processInput(GameTime gt);
  virtual void onRender();
  virtual void onInput();

  virtual void onResize(int width, int height);

  void run();

protected:
  Time timer;

private:
  void setCallbacks();
  static void framebuffer_size_callback(GLFWwindow *win, int width, int height);
};
