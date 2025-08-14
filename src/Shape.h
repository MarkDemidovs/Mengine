#pragma once
#include "../include/glad/glad.h"

class Shape {
public:
    virtual void init() = 0;     // initialize buffers/shaders
    virtual void draw() = 0;     // draw the shape
    virtual ~Shape() {};
};
