#pragma once
#include "Shape.h"

class Triangle : public Shape {
private:
    unsigned int VAO, VBO;
    unsigned int shaderProgram;

public:
    void init() override;
    void draw() override;
};
