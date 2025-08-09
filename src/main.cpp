#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.h"
#include "mesh.h"
#include "stb_image.h"

int main() {
    Window window(640, 480, "Square Example");

    if (!window.getNativeWindow()) {
        return -1;
    }

    // Vertices: pos(x,y,z) + tex coords(u,v)
    float vertices[] = {
        // First triangle
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  // top-left
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,  // bottom-left
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f,  // bottom-right

        // Second triangle
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f,  // top-left
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f,  // bottom-right
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f   // top-right
    };

    Mesh square(vertices, sizeof(vertices), 6);

    
    square.loadTexture("block.jpg");
    square.useTexture(true);

    while (!window.shouldClose()) {
        if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            window.setShouldClose(true);
        }

        window.setColor(0.2f, 0.3f, 0.3f, 1.0f);
        square.draw();
        window.load();
    }

    return 0;
}
