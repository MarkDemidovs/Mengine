#pragma once
#include "../include/glad/glad.h"
#include "./glm/glm.hpp"
#include <string>

class TexturedQuad {
private:
    unsigned int VAO, VBO, EBO;
    unsigned int shaderProgram;
    unsigned int textureID;
    int modelLoc;

public:
    TexturedQuad(const std::string& texturePath);
    ~TexturedQuad();

    void draw(const glm::mat4& model);
};
