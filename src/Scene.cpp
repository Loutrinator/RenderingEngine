//
// Created by Antoine on 04/01/2026.
//

#include "Scene.h"

Scene::Scene() {
}

void Scene::addObject(Object* obj) {
    objects.insert(objects.begin(), obj);
}

bool Scene::removeObject(Object* obj) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (*it == obj) {
            objects.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Object*>* Scene::getObjects() {
    return &objects;
}
