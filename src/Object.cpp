//
// Created by Antoine on 04/01/2026.
//

#include "Object.h"
#include "glad/glad.h"

Object::Object(Mesh& mesh, Material& material, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : _mesh(mesh),
                                                                                                          _material(material), _transform(position, rotation, scale) {
}
void Object::draw() {
    _material.bind();
    _mesh.bind();
    glDrawElements(GL_TRIANGLES, _mesh.getIndiceSize(), GL_UNSIGNED_INT, nullptr);
    _mesh.unbind();
}
