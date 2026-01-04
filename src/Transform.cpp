//
// Created by Antoine on 04/01/2026.
//

#include "Transform.h"

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
    this->position = pos;
    this->rotation = rot;
    this->scale = scale;
}