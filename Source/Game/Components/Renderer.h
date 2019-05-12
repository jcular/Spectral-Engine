#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/IRenderer.h"
#include "Render/VertexData.h"


namespace sp {
	class GameObject;

	class Renderer : public GameObjectComponent, public IRenderer {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(VertexData const & vertexData);
		void render() const override;

	private:
		void initializeVertexData(VertexData const & vertexData);

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
	};
}
