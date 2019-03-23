#pragma once

#include <string>

#include "Components/GameObjectComponent.h"
#include "Shader/ShaderProgram.h"
#include "UI/Font/Font.h"

namespace sp {
	class TextRenderer : public GameObjectComponent {
	public:
		TextRenderer(GameObject * const gameObject, Font const & font);

	public:
		void render() const;
		void setText(std::string const & text);

	private:
		void generateVertexData();

	private:
		unsigned int VAO;
		unsigned int VBO;
		std::string text;
		ShaderProgram shaderProgram;
		Font font;
	};
}
