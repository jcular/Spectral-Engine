#pragma once

#include <memory>
#include <string>

#include "Components/GameObjectComponent.h"
#include "Shader/ShaderProgram.h"
#include "UI/Font/Font.h"
#include "Utility/Math/Vector2.h"

namespace sp {
	class TextRenderer : public GameObjectComponent {
	public:
		TextRenderer(GameObject * const gameObject);

	public:
		void render() const;
		void setFont(std::string const & fontPath);
		void setText(std::string const & text);

	private:
		void generateVertexData();
		Vector2 const getPosition() const;

	private:
		unsigned int VAO;
		unsigned int VBO;
		std::string text;
		ShaderProgram shaderProgram;
		std::shared_ptr<Font const> font;
	};
}
