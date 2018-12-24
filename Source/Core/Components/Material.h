#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>
#include <vector>

#include "Core/Components/GameObjectComponent.h"
#include "Core/Texture.h"
#include "Core/Shader/ShaderProgram.h"

class Material : public GameObjectComponent {
public:
	Material(GameObject * gameObject);
	void initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath, std::string const texturePaths[], int textureCount);
	void use(glm::mat4x4 const & mvpMatrix) const;

private:
	std::unique_ptr<ShaderProgram> shaderProgram;
	std::vector<Texture> textureVector;
};
