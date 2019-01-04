#include "Material.h"

#include <string>
#include <vector>

#include "Texture.h"
#include "Shader/ShaderProgram.h"

#define MATERIAL_VARIABLE_NAME "material"

Material::Material(GameObject * gameObject) : GameObjectComponent(gameObject),
	ambientColor{ 1.0F },
	specularColor{ 1.0F },
	diffuseColor{ 1.0F },
	shininess{ 1.0F } {
}

void Material::initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath) {
	this->shaderProgram = std::make_shared<ShaderProgram>(vertexShaderPath, fragmentShaderPath);
}

void Material::use(glm::mat4x4 const & mvpMatrix, glm::mat4x4 const & modelMatrix) const {
	this->shaderProgram->use();

	this->shaderProgram->setMatrix4fv("mvpMatrix", glm::value_ptr(mvpMatrix));
	this->shaderProgram->setMatrix4fv("modelMatrix", glm::value_ptr(modelMatrix));
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

void Material::setAmbient(glm::vec3 const & ambientColor) {
	this->ambientColor = ambientColor;
}

void Material::setDiffuse(glm::vec3 const & diffuseColor) {
	this->diffuseColor = diffuseColor;
}

void Material::setSpecular(glm::vec3 const & specularColor) {
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
