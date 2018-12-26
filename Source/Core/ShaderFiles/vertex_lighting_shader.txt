#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 mvpMatrix;
uniform mat4 modelMatrix;

void main()
{
	FragPos = vec3(modelMatrix * vec4(aPos, 1.0F));
	Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;
    gl_Position = mvpMatrix * vec4(aPos, 1.0);
} 