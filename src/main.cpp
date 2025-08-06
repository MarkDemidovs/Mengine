#include "window.h"

int main() {
    Window window(640, 480, "My Custom Window");

    if (!window.shouldClose()) {
        // Main loop
        while (!window.shouldClose()) {
            // Close on ESC press
            if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                window.setShouldClose(true);
            }

            window.setColor(0.2f, 0.3f, 0.3f, 1.0f);

            window.load();
        }
    }

    return 0;
}
