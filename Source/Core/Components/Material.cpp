#include <Utility/SpString.h>

#include "Core/Components/Material.h"
#include "Shader/ShaderProgram.h"
#include "Texture.h"

#define MATERIAL_VARIABLE_NAME "material"

namespace sp {
	Material::Material(GameObject * gameObject) : GameObjectComponent(gameObject),
		ambientColor{ 1.0F },
		specularColor{ 1.0F },
		diffuseColor{ 1.0F },
		shininess{ 1.0F } {
	}

	void Material::initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath) {
		this->shaderProgram = std::make_shared<ShaderProgram>(vertexShaderPath, fragmentShaderPath);
	}

	void Material::use(Matrix4x4 const & mvpMatrix, Matrix4x4 const & modelMatrix) const {
		this->shaderProgram->use();

		this->shaderProgram->setMatrix4fv("mvpMatrix", mvpMatrix.getValuePtr());
		this->shaderProgram->setMatrix4fv("modelMatrix", modelMatrix.getValuePtr());
		SpString const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setVec3(materialVariablePrefix + SpString{ ".ambient" },
			this->ambientColor.x, this->ambientColor.y, this->ambientColor.z);
		this->shaderProgram->setVec3(materialVariablePrefix + SpString{ ".diffuse" },
			this->diffuseColor.x, this->diffuseColor.y, this->diffuseColor.z);
		this->shaderProgram->setVec3(materialVariablePrefix + SpString{ ".specular" },
			this->specularColor.x, this->specularColor.y, this->specularColor.z);
		this->shaderProgram->setFloat(materialVariablePrefix + SpString{ ".shininess" }, this->shininess);

		if (this->diffuseMapTexture != nullptr) {
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, this->diffuseMapTexture->getId());
		}

		if (this->specularMapTexture != nullptr) {
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, this->specularMapTexture->getId());
		}

		glActiveTexture(0);
	}

	std::weak_ptr<ShaderProgram> Material::getShaderProgram() const {
		return std::weak_ptr<ShaderProgram>(this->shaderProgram);
	}

	void Material::setAmbient(Vector3 const & ambientColor) {
		this->ambientColor = ambientColor;
	}

	void Material::setDiffuse(Vector3 const & diffuseColor) {
		this->diffuseColor = diffuseColor;
	}

	void Material::setSpecular(Vector3 const & specularColor) {
		this->specularColor = specularColor;
	}

	void Material::setShinines(float const shininess) {
		this->shininess = shininess;
	}

	void Material::setDiffuseMap(SpString const & texturePath) {
		this->shaderProgram->use();
		glActiveTexture(GL_TEXTURE0);
		this->diffuseMapTexture = std::make_unique<Texture>(texturePath, true,  GL_RGBA);
		SpString const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setInt(materialVariablePrefix + SpString{ ".diffuseMapTex" }, 0);
		glActiveTexture(0);
	}

	void Material::setSpecularMap(SpString const & texturePath) {
		this->shaderProgram->use();
		glActiveTexture(GL_TEXTURE1);
		this->specularMapTexture = std::make_unique<Texture>(texturePath, true, GL_RGBA);
		SpString const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setInt(materialVariablePrefix + SpString{ ".specularMapTex" }, 1);
		glActiveTexture(0);
	}
}
