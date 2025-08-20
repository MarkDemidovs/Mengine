#include "./Mengine.h"
#include "./Square.h"
#include "./Triangle.h"
#include "TexturedQuad.h"
#include "./glm/glm.hpp"
#include <GLFW/glfw3.h>
#include "glm/gtc/matrix_transform.hpp"

int main() {
    Mengine window(800, 800, "Shapes");
    
    TexturedQuad quad("block.jpg");

    Square square;
    Triangle triangle;

    square.init();
    triangle.init();

    while (!window.shouldClose()) {
        window.clear();
        window.colorBackground(0.1f, 0.1f, 0.1f);

        square.draw();
        triangle.draw();

        float time = glfwGetTime();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 1.0f));
        model = glm::translate(model, glm::vec3(0.5f * time, 0.0f, 0.0f));

        quad.draw(model);

        window.update();
    }
}
