#pragma once
#include <string>

class Mengine {
public:
    Mengine(int width, int height, const std::string& title);
    ~Mengine();

    void colorBackground(float r, float g, float b, float a = 1.0f);
    void clear();         // clears the screen
    void update();        // swaps buffers and polls events
    bool shouldClose() const;

private:
    struct Impl;          // PIMPL idiom to hide GLFW/GLAD details
    Impl* pImpl;
};
