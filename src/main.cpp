#include <GLFW/glfw3.h>

int main() {
    float redValue = 0.0f;
    float increment = 0.01f;
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a window of size 640x480 with your custom title
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Custom Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Main event loop
    while (!glfwWindowShouldClose(window)) {
        // Close window on ESC key press
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Dynamic Background Colour Changing
        redValue += increment;
        if (redValue > 1.0f || redValue < 0.0f){
            increment = -increment;
        }
        glClearColor(redValue, 0.3f, 0.3f, 1.0f);
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers to display the color
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }

    // Clean up and close GLFW
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
