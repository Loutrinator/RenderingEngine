//
// Created by Antoine on 04/01/2026.
//
#include <iostream>

#include "glm/gtc/type_ptr.hpp"

#include "Utils/FileReader.h"
#include "Shader.h"

Shader::Shader(const std::string& name) {
    _programId = glCreateProgram();
    //reading the two files and compiling them
    GLuint vertexShader = loadShader(name + ".vert", GL_VERTEX_SHADER);
    GLuint fragmentShader = loadShader(name + ".frag", GL_FRAGMENT_SHADER);

    //linking the two shaders to the shader program
    glAttachShader(_programId, vertexShader);
    glAttachShader(_programId, fragmentShader);
    glLinkProgram(_programId);

    //cleaning the two shader now that they are linked to the shader program
    glDetachShader(_programId, vertexShader);
    glDetachShader(_programId, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint linkSuccess;
    glGetProgramiv(_programId, GL_LINK_STATUS, &linkSuccess);

    if (linkSuccess == GL_FALSE) {
        int length;
        glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &length);

        std::string error;
        error.resize(length - 1);
        glGetProgramInfoLog(_programId, length, nullptr, (char*)error.data());

        throw std::runtime_error("Error while linking '" + name + "' shaders to program: " + error);
    }
}

Shader::~Shader() {
    glDeleteProgram(_programId);
}

GLuint Shader::loadShader(const std::string &path, GLenum type) {

    std::string source;
    GLuint shader = glCreateShader(type);
    try {
        source = FileReader::readFile("resources/shaders/" + path);
    }
    catch (const std::ios_base::failure &e) {
        std::cerr << "Unable to find or read shader file at path '" << path << "'" << std::endl;
        throw e;
    }

    const char *source_c = source.c_str();
    glShaderSource(shader, 1, &source_c, nullptr);
    glCompileShader(shader);

    GLint compileSuccess;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSuccess);
    if (compileSuccess == GL_FALSE) {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        std::string error;
        error.resize(length - 1);
        glGetShaderInfoLog(shader, length, nullptr, (char*)error.data());

        throw std::runtime_error("Error while compiling shader: " + error);
    }
    return shader;
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(_programId, name.c_str()), (int) value);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(_programId, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(_programId, name.c_str()), value);
}

void Shader::setVec3(const std::string& name, glm::vec3 value) const {
    auto toto = glGetUniformLocation(_programId, name.c_str());
    glUniform3fv(toto, 1, glm::value_ptr(value));
}
void Shader::setMat4(const std::string& name, glm::mat4 value) const {
    glUniformMatrix4fv(glGetUniformLocation(_programId, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::bind() const {
    glUseProgram(_programId);
}
