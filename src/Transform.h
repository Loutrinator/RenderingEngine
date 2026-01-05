//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_TRANSFORM_H
#define RENDERINGENGINE_TRANSFORM_H
#include "glm/glm.hpp"

class Transform {
public:
    Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
	glm::mat4 getLocalMatrix() const;

private:
    glm::vec3 _position{};
    glm::vec3 _rotation{};
    glm::vec3 _scale{};
};


#endif //RENDERINGENGINE_TRANSFORM_H