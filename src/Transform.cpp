//
// Created by Antoine on 04/01/2026.
//

#include "Transform.h"

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
    this->_position = pos;
    this->_rotation = rot;
    this->_scale = scale;
}
