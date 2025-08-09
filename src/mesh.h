#ifndef MESH_H
#define MESH_H

#include <cstddef> // for size_t

class Mesh {
private:
    unsigned int VAO, VBO;
    unsigned int vertexCount;

public:
    Mesh(const float* vertices, size_t size, unsigned int attribSize = 3);
    ~Mesh();

    void draw() const;
};

#endif
