#ifndef WINDOW_H
#define WINDOW_H

struct GLFWwindow; // forward declaration

class Window {
private:
    GLFWwindow* window;

public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void setShouldClose(bool value);
    void setColor(float r, float g, float b, float a) const;
    GLFWwindow* getNativeWindow() const { return window; }
    void load() const;
};

#endif
