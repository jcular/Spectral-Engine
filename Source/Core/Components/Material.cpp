#include <string>

#include "Components/Material.h"
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

	void Material::initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath) {
		this->shaderProgram = std::make_shared<ShaderProgram>(vertexShaderPath, fragmentShaderPath);
	}

	void Material::use(Matrix4x4 const & mvpMatrix, Matrix4x4 const & modelMatrix) const {
		this->shaderProgram->use();

		this->shaderProgram->setMatrix4fv("mvpMatrix", mvpMatrix.getValuePtr());
		this->shaderProgram->setMatrix4fv("modelMatrix", modelMatrix.getValuePtr());
		std::string const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setVec3(materialVariablePrefix + std::string{ ".ambient" },
			this->ambientColor.x, this->ambientColor.y, this->ambientColor.z);
		this->shaderProgram->setVec3(materialVariablePrefix + std::string{ ".diffuse" },
			this->diffuseColor.x, this->diffuseColor.y, this->diffuseColor.z);
		this->shaderProgram->setVec3(materialVariablePrefix + std::string{ ".specular" },
			this->specularColor.x, this->specularColor.y, this->specularColor.z);
		this->shaderProgram->setFloat(materialVariablePrefix + std::string{ ".shininess" }, this->shininess);
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

	void Material::setDiffuseMap(std::string const & texturePath) {
		this->shaderProgram->use();
		glActiveTexture(GL_TEXTURE0);
		this->diffuseMapTexture = std::make_unique<Texture>(texturePath, true,  GL_RGBA);
		std::string const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setInt(materialVariablePrefix + std::string{ ".diffuseMapTex" }, 0);
	}

	void Material::setSpecularMap(std::string const & texturePath) {
		this->shaderProgram->use();
		glActiveTexture(GL_TEXTURE1);
		this->diffuseMapTexture = std::make_unique<Texture>(texturePath, true, GL_RGBA);
		std::string const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		this->shaderProgram->setInt(materialVariablePrefix + std::string{ ".specularMapTex" }, 1);
	}
}
