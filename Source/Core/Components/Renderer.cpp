#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <string>

#include "Renderer.h"
#include "Components/Camera.h"
#include "Components/Material.h"
#include "Texture.h"
#include "Components/Transform.h"
#include "Shader/ShaderProgram.h"
#include "GameObject/GameObject.h"
#include "Utility/VertexData.h"

Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
}

void Renderer::initRenderer(VertexData const & vertexData) {
	this->initializeVertexData(vertexData);
}

void Renderer::renderObject() {
	auto material = this->gameObjectOwner->getComponent<Material>();

	glm::mat4x4 mvpMatrix{ 1.0F };
	glm::mat4x4 modelMatrix{ 1.0F };
	glm::vec3 cameraPos{ 0.0F };
	glm::vec3 cameraDir{ 0.0F };
	auto transformWeak = this->gameObjectOwner->getComponent<Transform>();
	if (auto transformShared = transformWeak.lock()) {
		modelMatrix = transformShared->getTransformMatrix();

		auto cameraShared = Camera::getMainCamera();
		mvpMatrix = (cameraShared->getProjectionMatrix() * (cameraShared->getViewMatrix() * modelMatrix));
		if (auto cameraTransformShared = cameraShared->getGameObject()->getComponent<Transform>().lock()) {
			cameraPos = cameraTransformShared->getPosition();
			cameraDir = -cameraTransformShared->getDirection();
		}
	}

	if (std::shared_ptr<Material> materialShared = material.lock()) {
		materialShared->use(mvpMatrix, modelMatrix);
		
		if (auto shaderProgram = materialShared->getShaderProgram().lock()) {
			shaderProgram->use();
			shaderProgram->setVec3("cameraPos", cameraPos.x, cameraPos.y, cameraPos.z);
			shaderProgram->setVec3("cameraDir", cameraDir.x, cameraDir.y, cameraDir.z);
		}
	}

	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Renderer::initializeVertexData(VertexData const & vertexData) {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	int const stride = vertexData.getStride() * sizeof(float);
	int attribArrayIndex = 0;

	glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
	glEnableVertexAttribArray(attribArrayIndex++);
	int step = 3;

	if (vertexData.hasNormalCoords()) {
		void const * const stepPointer = (void *)(step * sizeof(float));
		glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, stepPointer);
		glEnableVertexAttribArray(attribArrayIndex++);
		step += 3;
	}

	if (vertexData.hasUVCoords()) {
		void const * const stepPointer = (void *)(step * sizeof(float));
		glVertexAttribPointer(attribArrayIndex, 2, GL_FLOAT, GL_FALSE, stride, stepPointer);
		glEnableVertexAttribArray(attribArrayIndex++);
		step += 2;
	}

	glBufferData(GL_ARRAY_BUFFER, vertexData.getDataArraySize() * sizeof(float), vertexData.getDataArray(), GL_STATIC_DRAW);
	
	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexData.getIndexCount() * sizeof(int), vertexData.getIndexArray(), GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
