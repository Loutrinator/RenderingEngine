#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Engine.h"
#include "Scene.h"

int main()
{
    Engine::instance->setup(700,500,true);

    Engine::instance->run();
    return 0;
}
