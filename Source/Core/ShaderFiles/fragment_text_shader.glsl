#version 330 core

in vec2 TexCoord;
out vec4 color;

uniform sampler2D texture;
uniform vec3 TextColor;

void main()
{
	vec4 sampled = vec4(1.0F, 1.0F, 1.0F, texture(texture, TexCoord).r);
	color = sampled * (TextColor, 1.0F);
}
