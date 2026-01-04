//
// Created by Antoine on 04/01/2026.
//

#include "Object.h"

Object::Object(Mesh& mesh, Material& material, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : mesh(mesh),
    material(material), transform(position, rotation, scale) {
}
