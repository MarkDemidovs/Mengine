#ifndef MESH_H
#define MESH_H

#include "../include/glad/glad.h"
#include <iostream>

class Mesh {
private:
    unsigned int VAO, VBO;
    unsigned int vertexCount;
    unsigned int shaderProgram;

    // Shader source strings
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        uniform vec4 ourColor;  // color from uniform
        void main() {
            FragColor = ourColor;
        }
    )";

    unsigned int compileShader(unsigned int type, const char* source);
    void createShaderProgram();

public:
    Mesh(const float* vertices, size_t size, unsigned int attribSize = 3);
    ~Mesh();

    void draw() const;
    
    // Set color by passing normalized floats (0.0 - 1.0)
    void setColor(float r, float g, float b, float a = 1.0f) const;
};

#endif
