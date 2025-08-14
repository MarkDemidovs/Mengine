#pragma once
#include "Shape.h"

class Square : public Shape {
private:
    unsigned int VAO, VBO, EBO;
    unsigned int shaderProgram;

public:
    void init() override;
    void draw() override;
};
