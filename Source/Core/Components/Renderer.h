#pragma once

#include "Components/GameObjectComponent.h"
#include "Components/Interface/IRenderer.h"

namespace sp {
	class GameObject;
	class VertexData;

	class Renderer : public GameObjectComponent, IRenderer {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(VertexData const & vertexData);
		void render() const;

	private:
		void initializeVertexData(VertexData const & vertexData);

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
	};
}
