//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_TRANSFORM_H
#define RENDERINGENGINE_TRANSFORM_H
#include "glm/vec3.hpp"

class Transform {
public:
    Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
private:
    glm::vec3 position{};
    glm::vec3 rotation{};
    glm::vec3 scale{};
};


#endif //RENDERINGENGINE_TRANSFORM_H