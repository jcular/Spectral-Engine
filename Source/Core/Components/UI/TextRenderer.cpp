#include <glad/glad.h>

#include "Components/Camera.h"
#include "Components/UI/TextRenderer.h"
#include "Utility/Math/Matrix4x4.h"

sp::TextRenderer::TextRenderer(GameObject * const gameObject, Font const & font) : GameObjectComponent(gameObject),
	shaderProgram{ "vertex_text_shader.glsl", "fragment_text_shader.glsl" }, text{ "" }, font{ font } {
	this->generateVertexData();
}

void sp::TextRenderer::render() const {
	auto mainCamera = Camera::getMainCamera();
	auto projectionMatrix = mainCamera->getProjectionMatrix();
}

void sp::TextRenderer::setText(std::string const & text) {
	this->text = text;
}

void sp::TextRenderer::generateVertexData() {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	unsigned int const stride = (4 * sizeof(float));
	glVertexAttribIPointer(0, 4, GL_FLOAT, stride, 0);
	glEnableVertexAttribArray(0);

	unsigned int const quadSize = sizeof(float) * 4 * 6;
	glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
