//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_ENGINE_H
#define RENDERINGENGINE_ENGINE_H
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Scene.h"


class Engine {
public:
    void setup(int width, int height, bool debug);
    void run();

    static std::unique_ptr<Engine> instance;
    GLFWwindow* window;
    Scene scene;

    Engine();

private:
    int initWindow(int width, int height, bool debug);
    bool preRun();
    void loadScene(Scene* scene);
};

#endif //RENDERINGENGINE_ENGINE_H