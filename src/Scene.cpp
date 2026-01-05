//
// Created by Antoine on 04/01/2026.
//

#include "Scene.h"

Scene::Scene() {
}

void Scene::addObject(Object* obj) {
    _objects.insert(_objects.begin(), obj);
}

bool Scene::removeObject(Object* obj) {
    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        if (*it == obj) {
            _objects.erase(it);
            return true;
        }
    }
    return false;
}

void Scene::setCamera(Camera *cam) {
    _camera = cam;
}

///Calls the draw function on all object of scene
void Scene::drawScene() {
    _camera->update();

    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        Object* object = *it;
        glm::mat4 model = object->getTransform()->getLocalMatrix();
        glm::mat4 MVP = _camera->getProjection() * _camera->getView() * model;

        //sending the two matrices to the shader as uniform parameters
        Material& material = object->getMaterial();
        material.setMat4("mvp", MVP);
        material.setMat4("model", model);

        (*it)->draw();
    }
}

std::vector<Object*>* Scene::getObjects() {
    return &_objects;
}
