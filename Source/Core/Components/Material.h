#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Components/GameObjectComponent.h"
#include "Texture.h"
#include "Shader/ShaderProgram.h"
#include "Utility/Math/Matrix4x4.h"
#include "Utility/Math/Vector3.h"

namespace sp {
	class Material : public GameObjectComponent {
	public:
		Material(GameObject * gameObject);

	public:
		void initMaterial(std::string const & vertexShaderPath, std::string const & fragmentShaderPath);
		void use(Matrix4x4 const & mvpMatrix, Matrix4x4 const & modelMatrix) const;
		std::weak_ptr<ShaderProgram> getShaderProgram() const;
		void setAmbient(Vector3 const & ambientColor);
		void setDiffuse(Vector3 const & diffuseColor);
		void setSpecular(Vector3 const & specularColor);
		void setShinines(float const shininess);
		void setDiffuseMap(std::string const & texturePath);
		void setSpecularMap(std::string const & texturePath);

	private:
		Vector3 ambientColor;
		Vector3 diffuseColor;
		Vector3 specularColor;
		float shininess;
		std::shared_ptr<ShaderProgram> shaderProgram;
		std::unique_ptr<Texture> diffuseMapTexture;
		std::unique_ptr<Texture> specularMapTexture;
	};
}
