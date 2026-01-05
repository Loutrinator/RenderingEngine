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

///Calls the draw function on all object of scene
void Scene::drawScene() {
    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        (*it)->draw();
    }
}

std::vector<Object*>* Scene::getObjects() {
    return &_objects;
}
