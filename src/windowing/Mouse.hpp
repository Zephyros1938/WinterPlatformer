#pragma once
#include "../Utilities.hpp"
#include <GLFW/glfw3.h>

#ifndef MOUSEBUTTON_HPP
#define MOUSEBUTTON_HPP

enum MouseButton {
  Button1 = GLFW_MOUSE_BUTTON_1,
  Button2 = GLFW_MOUSE_BUTTON_2,
  Button3 = GLFW_MOUSE_BUTTON_3,
  Button4 = GLFW_MOUSE_BUTTON_4,
  Button5 = GLFW_MOUSE_BUTTON_5,
  Button6 = GLFW_MOUSE_BUTTON_6,
  Button7 = GLFW_MOUSE_BUTTON_7,
  Button8 = GLFW_MOUSE_BUTTON_8,
  Last = GLFW_MOUSE_BUTTON_LEFT,
  Left = GLFW_MOUSE_BUTTON_LEFT,
  Right = GLFW_MOUSE_BUTTON_RIGHT,
  Middle = GLFW_MOUSE_BUTTON_MIDDLE,
};

#endif

#ifndef MOUSE_HPP
#define MOUSE_HPP
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

class Mouse {
private:
  GLFWwindow *attachedWindow;

public:
  Mouse(GLFWwindow *parentWindow)
      : Delta(glm::vec2(0)), Position(glm::vec2(0)), NeedEnterWindow(true) {
    attachedWindow = parentWindow;
  };

  glm::vec2 Delta;
  glm::vec2 Position;
  bool NeedEnterWindow;

  void setPosition(double x, double y) {
    glfwSetCursorPos(attachedWindow, x, y);
  }
  
  bool isMouseButtonDown(int button)
  {
    
  }

  void update(double x, double y) {
    float xPos = (float)x;
    float yPos = (float)y;

    if (NeedEnterWindow) {
      Position = glm::vec2(xPos, yPos);
      NeedEnterWindow = false;
    }
    Delta = glm::vec2(xPos - Position.x, Position.y - yPos);
    Position = glm::vec2(xPos, yPos);
  }
};

#endif
