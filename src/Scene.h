//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_SCENE_H
#define RENDERINGENGINE_SCENE_H
#include <vector>

#include "Camera.h"
#include "Object.h"


class Scene {
public:
    Scene();
    void addObject(Object* obj);
    bool removeObject(Object* obj);
    void setCamera(Camera * cam);

    void drawScene();

    std::vector<Object*>* getObjects();


private:
    std::vector<Object*> _objects;
    Camera* _camera;
};


#endif //RENDERINGENGINE_SCENE_H