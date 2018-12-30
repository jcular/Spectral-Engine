#pragma once

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Core/Shader/Shader.h"
#include "Core/Utility/Vertices.h"
#include "Core/Components/Material.h"
#include "Core/Components/Transform.h"
#include "Core/Components/Renderer.h"
#include "Core/Components/Camera.h"
#include "Core/GameObject/GameObject.h"
#include "Core/Utility/VertexData.h"
#include "Core/Components/Rotator.h"

constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

GLFWwindow * initGLFWwindow();

void initScene(std::string const & executablePath) {
	GameObject * const cameraGameObject = new GameObject();
	auto cameraTransformWeak = cameraGameObject->addComponent<Transform>();
	auto cameraWeak = cameraGameObject->addComponent<Camera>();

	if (auto cameraShared = cameraWeak.lock()) {
		cameraShared->initCamera(glm::radians(45.0F), SCR_WIDTH, SCR_HEIGHT);
		Camera::setMainCamera(cameraShared);
	}

	std::string const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
	std::string const shadersFolderPath{ rootPath + std::string{"/../../../Source/Core/ShaderFiles"} };
	std::string const vertexShaderPath{ shadersFolderPath + std::string{ "/vertex_lighting_shader.txt" } };
	std::string const fragmentShaderPath{ shadersFolderPath + std::string{ "/fragment_lighting_shader.txt" } };
	std::string const resourcesFolderPath{ rootPath + std::string{ "/../../../Resources/Resources" } };
	std::string const texturePathArray[2]{
		resourcesFolderPath + std::string{ "/Art/wall.png" },
		resourcesFolderPath + std::string{ "/Art/awesomeface.png" }
	};

	constexpr int numberOfObjects = (sizeof(cubePositions) / sizeof(cubePositions[0]));

	GameObject * lightSourceGameObject = new GameObject;
	std::string const vertexLightingShaderPath{ shadersFolderPath + std::string{ "/vertex_shader.txt" } };
	std::string const fragmentLightingShaderPath{ shadersFolderPath + std::string{ "/fragment_lamp_shader.txt" } };
	std::weak_ptr<Material> material = lightSourceGameObject->addComponent<Material>();
	if (auto materialShared = material.lock()) {
		const int numberOfTextures = 2;
		materialShared->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath, texturePathArray, numberOfTextures);
	}

	std::weak_ptr<Renderer> rendererWeak = lightSourceGameObject->addComponent<Renderer>();
	if (auto rendererShared = rendererWeak.lock()) {
		VertexData vertexData{ verticesUV, (int)(sizeof(verticesUV) / sizeof(float)), indices, (int)sizeof(indices), true, false };
		rendererShared->initRenderer(vertexData);
	}

	std::weak_ptr<Transform> lightSourceTransformWeak = lightSourceGameObject->addComponent<Transform>();
	if (auto transformShared = lightSourceTransformWeak.lock()) {
		int const lightSourceIndex = numberOfObjects - 1;
		transformShared->setPosition(cubePositions[lightSourceIndex]);
	}

	int const numberOfBoxes = numberOfObjects - 1;
	GameObject * boxObjects = new GameObject[numberOfBoxes];
	
	for (int i = 0; i < numberOfBoxes; ++i) {
		std::weak_ptr<Material> material = boxObjects[i].addComponent<Material>();
		if (auto materialShared = material.lock()) {
			constexpr int numberOfTextures = sizeof(texturePathArray) / sizeof(std::string);
			materialShared->initMaterial(vertexShaderPath, fragmentShaderPath, texturePathArray, numberOfTextures);
			
			auto shaderProgramWeak = materialShared->getShaderProgram();
			if (auto shaderProgramShared = shaderProgramWeak.lock()) {
				shaderProgramShared->setVec3("objectColor", 0.8F, 0.3F, 0.12F);
				shaderProgramShared->setVec3("lightColor", 0.5F, 0.6F, 0.89F);
				
				if (auto lightSourceTransformShared = lightSourceTransformWeak.lock()) {
					auto lightPos = lightSourceTransformShared->getPosition();
					shaderProgramShared->setVec3("lightPos", lightPos.x, lightPos.y, lightPos.z);
				}

				if (auto cameraTransformShared = cameraTransformWeak.lock()) {
					auto cameraPos = cameraTransformShared->getPosition();
					shaderProgramShared->setVec3("cameraPos", cameraPos.x, cameraPos.y, cameraPos.z);
				}
			}
		}

		if (i % 2) {
			boxObjects[i].addComponent<Rotator>();
		}

		std::weak_ptr<Renderer> renderer = boxObjects[i].addComponent<Renderer>();
		if (auto rendererShared = renderer.lock()) {
			VertexData vertexData{ verticesNormal, (int)(sizeof(verticesNormal) / sizeof(float)), indices, (int)(sizeof(indices) / sizeof(int)), false, true };
			rendererShared->initRenderer(vertexData);
		}

		std::weak_ptr<Transform> transform = boxObjects[i].addComponent<Transform>();
		if (auto transformShared = transform.lock()) {
			transformShared->setPosition(cubePositions[i]);
		}
	}
}

GLFWwindow * setupWindow() {
	auto window = initGLFWwindow();

	if (window == NULL) {
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD." << std::endl;
		return nullptr;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window,
		[](GLFWwindow * window, int width, int height) {
		glViewport(0, 0, width, height);
	});

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	return window;
}

GLFWwindow * initGLFWwindow() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window = glfwCreateWindow(800, 600, "Spectral Engine", NULL, NULL);

	return window;
}
