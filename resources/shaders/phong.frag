#version 430 core

in vec3 fragPos;
in vec3 normals;
in vec2 uvs;

out vec4 fragColor;

void main()
{
    fragColor = vec4(0.0f, uvs.y, 0.0f, 1.0f);
}