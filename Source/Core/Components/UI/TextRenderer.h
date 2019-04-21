#pragma once

#include <memory>
#include <Utility/SpString.h>

#include "Components/GameObjectComponent.h"
#include "Components/Interface/IRenderer.h"
#include "Shader/ShaderProgram.h"
#include "UI/Font/Font.h"
#include "Utility/Math/Vector2.h"

namespace sp {
	class TextRenderer : public GameObjectComponent, public IRenderer {
	public:
		TextRenderer(GameObject * const gameObject);

	public:
		void render() const override;
		void setFont(SpString const & fontPath);
		void setText(SpString const & text);

	private:
		void generateVertexData();
		Vector2 const getPosition() const;
		Vector2 const getScale() const;

	private:
		unsigned int VAO;
		unsigned int VBO;
		SpString text;
		ShaderProgram shaderProgram;
		std::shared_ptr<Font const> font;
	};
}
