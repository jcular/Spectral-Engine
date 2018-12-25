#include "Material.h"

#include <string>
#include <vector>

#include "Texture.h"
#include "Shader/ShaderProgram.h"

Material::Material(GameObject * gameObject) : GameObjectComponent(gameObject) {
}

void Material::initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath, std::string const texturePaths[], int textureCount) {
	this->shaderProgram = std::make_unique<ShaderProgram>(vertexShaderPath, fragmentShaderPath);
	for (int i = 0; i < textureCount; ++i) {
		std::string const texturePath = texturePaths[i];
		Texture texture{ texturePath, true,  GL_RGBA };
		this->textureVector.push_back(texture);
	}
}

void Material::use(glm::mat4x4 const & mvpMatrix) const {
	this->shaderProgram->use();

	this->shaderProgram->setMatrix4fv("mvpMatrix", glm::value_ptr(mvpMatrix));

	for (unsigned int i = 0; i < this->textureVector.size(); ++i) {
		GLenum const activeTexture = (GL_TEXTURE0 + i);
		glActiveTexture(activeTexture);
		unsigned int const textureId = this->textureVector.at(i).getId();
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
}
