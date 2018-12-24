#include "Renderer.h"

Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
}

void Renderer::initRenderer(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount) {
	this->initializeVertexData(vertices, vertexCount, elementIndices, indexCount);
}

void Renderer::renderObject() {
	auto material = this->gameObjectOwner->getComponent<Material>();

	glm::mat4x4 mvpMatrix{ 1.0F };
	auto transformWeak = this->gameObjectOwner->getComponent<Transform>();
	if (auto transformShared = transformWeak.lock()) {
		glm::vec3 position = transformShared->getPosition();
		glm::mat4x4 model{ 1.0F };
		model = glm::translate(model, position);

		auto cameraShared = Camera::getMainCamera();
		mvpMatrix = (cameraShared->getProjectionMatrix() * (cameraShared->getViewMatrix() * model));
	}

	if (std::shared_ptr<Material> materialShared = material.lock()) {
		material.lock()->use(mvpMatrix);
	}

	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Renderer::initializeVertexData(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount) {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	int stride = 5 * sizeof(float);
	void const * const VBOPointer = (void *)0;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, VBOPointer);
	glEnableVertexAttribArray(0);

	void const * const EBOPointer = (void *)(3 * sizeof(float));
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, EBOPointer);
	glEnableVertexAttribArray(1);

	glBufferData(GL_ARRAY_BUFFER, vertexCount, vertices, GL_STATIC_DRAW);
	
	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount, elementIndices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
