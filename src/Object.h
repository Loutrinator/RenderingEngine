//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_OBJECT_H
#define RENDERINGENGINE_OBJECT_H
#include "Material.h"
#include "Mesh.h"
#include "Transform.h"
#include "glm/vec3.hpp"


class Object {
public:
    Object(Mesh& mesh, Material&, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

    private:
    Mesh& mesh;
    Material& material;
    Transform transform;
};


#endif //RENDERINGENGINE_OBJECT_H