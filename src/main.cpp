#include "Shader.hpp"
#include "game/Camera.hpp"
#include "windowing/Window.hpp"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
using namespace std;

class MyGame : public Window {
public:
  Shader *s;
  Camera *camera;
  unsigned int VAO = 0;
  unsigned int VBO = 0;
  double countDown = 0;
  MyGame() : Window() {}

  void onInit() override {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    std::cout << "Initialized MyGame window\n";

    float vertices[] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                        0.0f, 0.5f, -0.5f, 0.0f};

    // Vertex Array Object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertex Buffer Object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex Attribute Pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);
    s = new Shader("Shaders/test.vert", "Shaders/test.frag");
    camera = new Camera();
    glfwSetWindowSize(handle, Hints.width - 1, Hints.height);
    glfwSetWindowSize(handle, Hints.width, Hints.height);
  }

  void onUpdate(GameTime gt) override {
    double dt = gt.delta;
    // std::cout << "Updating, Elapsed = " << gt.total << "\n";
  }

  void onRender() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    s->use();
    s->setMat4("model", glm::identity<glm::mat4>());
    s->setMat4("view", camera->GetViewMatrix());
    s->setMat4("projection", camera->GetProjectionMatrix());
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }

  void onInput() override {
    if (getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      setShouldClose(true);
    }
  }

  void processInput(GameTime gt) override {
    double dt = gt.delta;
    if (getKey(GLFW_KEY_W) == GLFW_PRESS)
      camera->Position += camera->MovementSpeed * camera->Front * (float)dt;
    if (getKey(GLFW_KEY_S) == GLFW_PRESS)
      camera->Position -= camera->MovementSpeed * camera->Front * (float)dt;
    if (getKey(GLFW_KEY_A) == GLFW_PRESS)
      camera->Position -=
          glm::normalize(glm::cross(camera->Front, camera->Up)) *
          camera->MovementSpeed * (float)dt;
    if (getKey(GLFW_KEY_D) == GLFW_PRESS)
      camera->Position +=
          glm::normalize(glm::cross(camera->Front, camera->Up)) *
          camera->MovementSpeed * (float)dt;
  }

  void onResize(int width, int height) override {
    camera->SetAspect((float)width / (float)height);
    glViewport(0, 0, width, height);
  }

  ~MyGame() {
    delete s;
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
  }
};

int main() {
  try {
    MyGame game;
    game.run();
  } catch (const std::exception &e) {
    std::cerr << "Fatal error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
