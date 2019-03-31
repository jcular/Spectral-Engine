#include <glad/glad.h>
#include <memory>
#include <string>

#include "Components/Camera.h"
#include "Components/Transform.h"
#include "Components/UI/TextRenderer.h"
#include "GameObject/GameObject.h"
#include "UI/Font/Character.h"
#include "Utility/Math/Matrix4x4.h"
#include "Utility/ResourcesPathProvider.h"


sp::TextRenderer::TextRenderer(GameObject * const gameObject) : GameObjectComponent(gameObject),
	shaderProgram{ 
		ResourcesPathProvider::getShaderFilesDirectoryPath() + std::string{ "/vertex_text_shader.glsl" },
		ResourcesPathProvider::getShaderFilesDirectoryPath() + std::string{ "/fragment_text_shader.glsl" } },
	text{ "" } {
	this->generateVertexData();
}

void sp::TextRenderer::render() const {
	auto mainCamera = Camera::getMainCamera();
	auto projectionMatrix = mainCamera->getProjectionMatrix();

	this->shaderProgram.use();
	this->shaderProgram.setMatrix4fv("projectionMatrix", projectionMatrix.getValuePtr());
	this->shaderProgram.setVec3("TextColor", 0.9F, 0.65F, 0.13F);
	glActiveTexture(GL_TEXTURE0);

	glBindVertexArray(this->VAO);
	Vector2 const position = this->getPosition();

	std::string::const_iterator characterIterator;
	float characterOffsetX = 0.0F;

	for (characterIterator = this->text.begin(); characterIterator != text.end(); ++characterIterator) {
		Character const character = this->font->getCharacter(*characterIterator);
		Vector2 const currentCharPos = position + Vector2{ characterOffsetX, 0.0F };
		Vector2 const characterBearing{ (float)character.bitmapLeft, (float)character.bitmapTop };
		Vector2 const textureOrigin = currentCharPos + characterBearing;

		float const characterVertices[6][4] {
			{ textureOrigin.x, textureOrigin.y, 0.0F, 1.0F },
			{ textureOrigin.x + character.width, textureOrigin.y, 1.0F, 1.0F },
			{ textureOrigin.x, textureOrigin.y - character.height, 0.0F, 0.0F },
			{ textureOrigin.x, textureOrigin.y - character.height, 0.0F, 0.0F },
			{ textureOrigin.x + character.width, textureOrigin.y - character.height, 1.0F, 0.0F },
			{ textureOrigin.x + character.width, textureOrigin.y, 1.0F, 1.0F }
		};

		glBindTexture(GL_TEXTURE_2D, character.textureId);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(characterVertices), characterVertices);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		characterOffsetX += character.advance;
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void sp::TextRenderer::setFont(std::string const & fontPath) {
	this->font = Font::getFont(fontPath);
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	unsigned int const quadSize = sizeof(float) * 4 * 6;
	glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

sp::Vector2 const sp::TextRenderer::getPosition() const {
	std::weak_ptr<Transform> transformWeak = this->getGameObject()->getComponent<Transform>();
	
	if (auto transformShared = transformWeak.lock()) {
		return transformShared->getPosition();
	}

	return Vector2{ 0.0F, 0.0F };
}
