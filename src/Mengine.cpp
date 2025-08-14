#include "Mengine.h"
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

struct Mengine::Impl {
    GLFWwindow* window;

    Impl(int width, int height, const std::string& title) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW\n";
            std::exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            std::exit(EXIT_FAILURE);
        }

        glViewport(0, 0, width, height);
    }

    ~Impl() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

Mengine::Mengine(int width, int height, const std::string& title)
    : pImpl(new Impl(width, height, title)) {}

Mengine::~Mengine() { delete pImpl; }

void Mengine::colorBackground(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Mengine::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Mengine::update() {
    glfwSwapBuffers(pImpl->window);
    glfwPollEvents();
}

bool Mengine::shouldClose() const {
    return glfwWindowShouldClose(pImpl->window);
}
