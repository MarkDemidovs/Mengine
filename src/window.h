#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window;

public:
    // Constructor creates the window
    Window(int width, int height, const char* title);

    // Destructor cleans up
    ~Window();

    // Check if window should close
    bool shouldClose() const;

    // Set the window to close
    void setShouldClose(bool value);

    // Clear color buffer with given RGBA
    void setColor(float r, float g, float b, float a) const;

    GLFWwindow* getNativeWindow() const { return window; };

    // Polls events and swaps buffers
    void load() const;

};

#endif
