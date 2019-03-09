#include "TextRenderer.h"

sp::TextRenderer::TextRenderer(GameObject * const gameObject, Font const & font) : GameObjectComponent(gameObject),
	shaderProgram{ "vertex_text_shader.glsl", "fragment_text_shader.glsl" }, text{ "" }, font{ font } {
}

void sp::TextRenderer::render() const {
}

void sp::TextRenderer::setText(std::string const & text) {
	this->text = text;
}
