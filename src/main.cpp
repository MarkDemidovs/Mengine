#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.h"
#include "mesh.h"
int main() {
    Window window(640, 480, "Square Example");

    if (!window.getNativeWindow()) {
        return -1;
    }

    float vertices[] = {
        // First triangle
        -0.5f,  0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  
         0.5f, -0.5f, 0.0f,  

        // Second triangle
        -0.5f,  0.5f, 0.0f,  
         0.5f, -0.5f, 0.0f,  
         0.5f,  0.5f, 0.0f   
    };

    Mesh square(vertices, sizeof(vertices));

    while (!window.shouldClose()) {
        if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            window.setShouldClose(true);
        }

        window.setColor(0.2f, 0.3f, 0.3f, 1.0f);
        square.setColor(1.0f, 0.0f, 0.0f); 
        square.draw();
        window.load();
    }

    return 0;
}