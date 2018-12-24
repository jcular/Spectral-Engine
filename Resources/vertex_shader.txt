#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCoord;

uniform mat4 mvpMatrix;

out vec2 texCoordinates;

void main()
{
	texCoordinates = texCoord;
    gl_Position = mvpMatrix * vec4(aPos, 1.0);
}