//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_MESH_H
#define RENDERINGENGINE_MESH_H

#include <glad/glad.h>

class Mesh {
public:
    Mesh();
    ~Mesh();

    void bind();
    void unbind();

    void setVertices(const float *vertices, size_t size);
    void setIndices(const unsigned int *indices, size_t size);
    int getIndiceSize() const;

private:
    GLuint _vao; //Vertex array object
    GLuint _vbo; //Vertex buffer object
    GLuint _ibo; //Indices buffer object
    int _indicesSize;
};

#endif //RENDERINGENGINE_MESH_H