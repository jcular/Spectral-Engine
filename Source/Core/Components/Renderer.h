#pragma once

#include "Components/GameObjectComponent.h"

namespace sp {
	class GameObject;
	class VertexData;

	class Renderer : public GameObjectComponent {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(VertexData const & vertexData);
		void renderObject();

	private:
		void initializeVertexData(VertexData const & vertexData);

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
	};
}
