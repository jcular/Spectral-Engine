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
	void initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath, std::string const texturePaths[], int textureCount);
	void use(glm::mat4x4 const & mvpMatrix, glm::mat4x4 const & modelMatrix) const;
	std::weak_ptr<ShaderProgram> getShaderProgram() const;

private:
	std::shared_ptr<ShaderProgram> shaderProgram;
	std::vector<Texture> textureVector;
};
