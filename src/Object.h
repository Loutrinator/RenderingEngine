//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_OBJECT_H
#define RENDERINGENGINE_OBJECT_H

#include "Material.h"
#include "Mesh.h"
#include "Transform.h"
#include "glm/glm.hpp"


class Object {
public:
    Object(Mesh& mesh, Material&, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    void draw();
    Mesh& getMesh();
    Material& getMaterial();
    Transform* getTransform();

    private:
    Mesh& _mesh;
    Material& _material;
    Transform _transform;
};


#endif //RENDERINGENGINE_OBJECT_H