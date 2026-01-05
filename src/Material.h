//
// Created by Antoine on 04/01/2026.
//

#ifndef RENDERINGENGINE_MATERIAL_H
#define RENDERINGENGINE_MATERIAL_H

#include "Shader.h"
#include "glm/glm.hpp"

class Material {
public:
    Material(Shader* shader, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular, float shininess);
    void bind();
    Shader* getShader();
    void setMat4(const std::string& name, glm::mat4 value) const;
private:
    Shader* _shader;
    const glm::vec3& _ambient;
    const glm::vec3& _diffuse;
    const glm::vec3& _specular;
    float _shininess;
};


#endif //RENDERINGENGINE_MATERIAL_H