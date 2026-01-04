//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_ENGINE_H
#define RENDERINGENGINE_ENGINE_H
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Engine {
public:

    void setup(int width, int height, bool debug);
    void run();

    static std::unique_ptr<Engine> instance;
    GLFWwindow* window{};

    Engine();

private:
    int initWindow(int width, int height, bool debug);
};

#endif //RENDERINGENGINE_ENGINE_H