//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_SCENE_H
#define RENDERINGENGINE_SCENE_H
#include <vector>

#include "Object.h"


class Scene {
public:
    Scene();
    void addObject(Object* obj);
    bool removeObject(Object* obj);

    void drawScene();

    std::vector<Object*>* getObjects();
private:
    std::vector<Object*> _objects;
};


#endif //RENDERINGENGINE_SCENE_H