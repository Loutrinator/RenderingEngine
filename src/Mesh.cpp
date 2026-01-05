//
// Created by Antoine on 04/01/2026.
//

#include "Mesh.h"

#include "glad/glad.h"

Mesh::Mesh() {

    glGenVertexArrays(1, &_vao); //Creating the Vertex array buffer

    bind(); //binding it to the GPU

    //Telling the GPU how to read the VBO by indicating in the VAO what are its attributes
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);//The param is 3 float long, it will contain the position of the vertice
    glEnableVertexAttribArray(0);
	glVertexAttribBinding(0, 0);
	glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);//The param is 3 float long, it will contain the normal direction of the vertice
	glEnableVertexAttribArray(1);
	glVertexAttribBinding(1, 0);
	glVertexAttribFormat(2, 2, GL_FLOAT, GL_FALSE, 0);//The param is 2 float long, it will contain the uv of the vertice
	glEnableVertexAttribArray(2);
	glVertexAttribBinding(2, 0);

    unbind(); //unbinding the VAO
}

Mesh::~Mesh() {
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ibo);
	glDeleteVertexArrays(1, &_vao);
}

void Mesh::bind() {
	glBindVertexArray(_vao);
}

void Mesh::unbind() {
	glBindVertexArray(0);
}

void Mesh::setVertices(const float *vertices, size_t size) {

	glGenBuffers(1, &_vbo); //Creating a buffer. This one will contain the vertices data

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	bind();
	glBindVertexBuffer(0,_vbo,0,8*sizeof(GLfloat)); //binding the newly created vertex buffer to the VAO of the material
	unbind();
}

void Mesh::setIndices(const unsigned int *indices, size_t size) {

	glGenBuffers(1, &_ibo); //Creating a buffer. This one will contain the indices data

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	bind();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo); //binding the newly created indices buffer to the VAO of the material
	unbind();
	_indicesSize = size;
}
int Mesh::getIndiceSize() const {
	return _indicesSize;
}