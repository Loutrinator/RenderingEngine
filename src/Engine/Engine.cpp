//
// Created by Antoine on 04/01/2026.
//

#include "Engine.h"
#include <iostream>
#include <memory>


std::unique_ptr<Engine> Engine::instance = std::make_unique<Engine>();


Engine::Engine() {
}

///Preparing the engine to run
void Engine::setup(int width, int height, bool debug) {

    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    initWindow(width, height,debug);
}

///Initializing all required components to render in a window
int Engine::initWindow(int width, int height, bool debug) {

    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    if(debug){
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    }

    // Creating the window
    window = glfwCreateWindow(width, height, "Rendering Engine", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL functions via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    glViewport(0, 0, width, height); //set la zone sur laquelle tu fais ton rendu

    std::cout<<"Engine set up to render in " << width << "*" << height << "px\n";
    return 1;
}

void Engine::run() {

    std::cout<<"Running the engine\n";
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout<<"Closing the engine\n";
}
