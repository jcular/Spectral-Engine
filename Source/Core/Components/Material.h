#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>
#include <vector>

#include "Components/GameObjectComponent.h"
#include "Texture.h"
#include "Shader/ShaderProgram.h"

class Material : public GameObjectComponent {
public:
	Material(GameObject * gameObject);

public:
	void initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath);
	void use(glm::mat4x4 const & mvpMatrix, glm::mat4x4 const & modelMatrix) const;
	std::weak_ptr<ShaderProgram> getShaderProgram() const;
	void setAmbient(glm::vec3 const & ambientColor);
	void setDiffuse(glm::vec3 const & diffuseColor);
	void setSpecular(glm::vec3 const & specularColor);
	void setShinines(float const shininess);
	void setDiffuseMap(std::string const & texturePath);
	void setSpecularMap(std::string const & texturePath);

private:
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	float shininess;
	std::shared_ptr<ShaderProgram> shaderProgram;
	std::unique_ptr<Texture> diffuseMapTexture;
	std::unique_ptr<Texture> specularMapTexture;
};
