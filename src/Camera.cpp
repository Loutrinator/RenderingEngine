//
// Created by Antoine on 05/01/2026.
//
#define GLM_ENABLE_EXPERIMENTAL
#include "Camera.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, glm::vec3 position) : _fov(fov), _position(position)
{

}

void Camera::update()
{
    _forward = glm::vec3(0.0f, 1.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    _right = glm::normalize(glm::cross(up, _forward));
    _up = glm::cross(_forward, _right);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float ratio = viewport[2] / (float) viewport[3];
    //std::cout << _position.x << " " << _position.y << " " << _position.z << "\n";
    _projection = glm::perspective(glm::radians(_fov), ratio, 0.01f, 100.0f);
    _view = glm::lookAt(_position, _position + _forward, _up);
}

glm::mat4 Camera::getView() {
    return _projection;
}

glm::mat4 Camera::getProjection() {
    return _view;
}
