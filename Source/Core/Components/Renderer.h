#pragma once

#include "Components/GameObjectComponent.h"

class GameObject;

class Renderer : public GameObjectComponent {
public:
	Renderer(GameObject * const gameObjectOwner);
	void initRenderer(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount, bool const uvCoordsIncluded);
	void renderObject();

private:
	void initializeVertexData(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount, bool const uvCoordsIncluded);

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
};

