//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_SHADER_H
#define RENDERINGENGINE_SHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>


class Shader {
public:
    Shader(const std::string& name);
    ~Shader();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string& name, glm::vec3 value) const;
    void setMat4(const std::string& name, glm::mat4 value) const;

    void bind() const;

private:
    GLuint _programId;
	static GLuint loadShader(const std::string& path, GLenum type);
};


#endif //RENDERINGENGINE_SHADER_H