#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <string>

#include "Core/Components/Camera.h"
#include "Core/Components/GameObjectComponent.h"
#include "Core/Components/Material.h"
#include "Core/Texture.h"
#include "Core/Components/Transform.h"
#include "Core/Shader/ShaderProgram.h"

class Renderer : public GameObjectComponent {
public:
	Renderer(GameObject * const gameObjectOwner);
	void initRenderer(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount);
	void renderObject();

private:
	void initializeVertexData(float const * const vertices, int const vertexCount, unsigned int const * const elementIndices, int const indexCount);

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
};

