//
// Created by Antoine on 04/01/2026.
//

#include "Engine.h"
#include <iostream>
#include <memory>

#include "Shader.h"


std::unique_ptr<Engine> Engine::instance = std::make_unique<Engine>();


Engine::Engine() {
    scene = Scene();
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

bool Engine::preRun()
{

}

void Engine::run()
{
    Shader shader("firstShader");

    //FIRST MESH
    Mesh triangleMesh = Mesh();
    float triangleVertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    unsigned int triangleIndices[] = {
        0, 1, 2
    };
    triangleMesh.setVertices(triangleVertices, sizeof(triangleVertices) / sizeof(float));
    triangleMesh.setIndices(triangleIndices, sizeof(triangleIndices) / sizeof(unsigned int));

    //FIRST MATERIAL
    glm::vec3 redDiffuse(1.0f, 0.0f, 0.0f);
    glm::vec3 redAmbient = redDiffuse;
    glm::vec3 redSpecular(0.5f);
    float redShininess = 256;
    Material redMaterial(&shader, redAmbient, redDiffuse, redSpecular, redShininess);

    Object triangle = Object(triangleMesh, redMaterial, glm::vec3(0,1,0), glm::vec3(0,0,0), glm::vec3(1,1,1));

    scene.addObject(&triangle);


    std::cout<<"Running the engine\n";
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        scene.drawScene();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout<<"Closing the engine\n";
}

void Engine::oldTest()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    //VERTEX SHADER
    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }

    //FRAGMENT SHADER
    const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";
    unsigned int fragmentShader;
    fragmentShader  = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    success = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }

    //SHADER PROGRAM
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    success = 0;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    //LOOP
    unsigned int VBO;
    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 1. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 2. use our shader program when we want to render an object
    glUseProgram(shaderProgram);
    // 3. now draw the object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 4. draw the object
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);


    glDrawArrays(GL_TRIANGLES, 0, 3);
}
