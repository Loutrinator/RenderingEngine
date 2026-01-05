//
// Created by Antoine on 04/01/2026.
//
#define GLM_ENABLE_EXPERIMENTAL
#include "Transform.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) {
    this->_position = pos;
    this->_rotation = rot;
    this->_scale = scale;
}

glm::mat4 Transform::getLocalMatrix() const {
    return glm::translate(_position) * glm::eulerAngleXYZ(_rotation.x, _rotation.y, _rotation.z) * glm::scale(_scale);
}