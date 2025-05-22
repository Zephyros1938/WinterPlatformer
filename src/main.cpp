#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
#include "Window.hpp"
using namespace std;

class MyGame : public Window {
public:
    MyGame() : Window() {}

    void onInit() override {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        std::cout << "Initialized MyGame window\n";
    }

    void onUpdate(double dt) override {
        // Game logic here
        std::cout << "Updating, dt = " << dt << " seconds\n";
    }

    void onRender() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Rendering code here
    }

    void onInput() override {
        if (getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            setShouldClose(true);
        }
    }
};


int main() {
  MyGame w = MyGame();

  w.run();

  return 0;
}
