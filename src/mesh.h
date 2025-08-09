#pragma once

#include <string>
#include <iostream>
#include "../include/glad/glad.h"

class Mesh {
private:
    unsigned int VAO, VBO;
    unsigned int textureID = 0;
    bool textured = false;

    float color[3] = {1.0f, 1.0f, 1.0f}; // default white color

    unsigned int shaderProgram;

    // Uniform locations cached for performance
    int colorLoc = -1;
    int useTextureLoc = -1;
    int texLoc = -1;

    unsigned int vertexCount;

    // Shader sources
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;

        out vec2 TexCoord;

        void main() {
            gl_Position = vec4(aPos, 1.0);
            TexCoord = aTexCoord;
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        in vec2 TexCoord;

        uniform vec3 ourColor;
        uniform sampler2D texture1;
        uniform bool useTexture;

        void main() {
            if(useTexture) {
                vec4 sampled = texture(texture1, TexCoord);
                FragColor = vec4(ourColor, 1.0) * sampled;
            } else {
                FragColor = vec4(ourColor, 1.0);
            }
        }
    )";

    // Internal helper functions
    unsigned int compileShader(unsigned int type, const char* source);
    void setupShader();

public:
    Mesh(const float* vertices, size_t sizeInBytes, unsigned int vertexCount);
    ~Mesh();

    bool loadTexture(const std::string& path);
    void useTexture(bool enable);
    void setColor(float r, float g, float b);
    void draw();
};
