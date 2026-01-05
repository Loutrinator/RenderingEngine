//
// Created by Antoine on 05/01/2026.
//

#ifndef RENDERINGENGINE_CAMERA_H
#define RENDERINGENGINE_CAMERA_H
#include "glm/glm.hpp"


class Camera {
public:
    Camera(float fov, glm::vec3 position);
    void update();


    glm::mat4 getView();
    glm::mat4 getProjection();

private:
    float _fov;
    glm::vec3 _position;
    glm::vec3 _forward;
    glm::vec3 _up;
    glm::vec3 _right;
    glm::mat4 _view;
    glm::mat4 _projection;
};


#endif //RENDERINGENGINE_CAMERA_H
