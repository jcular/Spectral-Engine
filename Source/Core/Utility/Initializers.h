#pragma once

#include <memory>
#include <random>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <time.h>

#include "Core/Shader/Shader.h"
#include "Core/Utility/Vertices.h"
#include "Core/Components/Material.h"
#include "Core/Components/Transform.h"
#include "Core/Components/Renderer.h"
#include "Core/Components/Camera.h"
#include "Core/GameObject/GameObject.h"
#include "Core/Utility/VertexData.h"
#include "Core/Components/Rotator.h"
#include "Utility/Math/Radian.h"

namespace sp {
	constexpr unsigned int SCR_WIDTH = 800;
	constexpr unsigned int SCR_HEIGHT = 600;
	std::default_random_engine generator{ (unsigned int)time(0) };
	std::uniform_real_distribution<float> distribution{ 0.0F, 1.0F };

	GLFWwindow * initGLFWwindow();

	void setRandomColors(std::weak_ptr<Material> materialWeak) {
		if (auto materialShared = materialWeak.lock()) {
			Vector3 ambient{ 0.2F };
			materialShared->setAmbient(ambient);
		
			Vector3 diffuse{ distribution(generator) };
			materialShared->setDiffuse(diffuse);

			Vector3 specular{ distribution(generator) };
			materialShared->setSpecular(specular);

			float shininess{ 1.0F + 31 * distribution(generator) };
			materialShared->setShinines(shininess);
		}
	}

	GameObject * createLight(std::string const & shadersFolderPath, std::string const texturePathArray[], int const lightSourceIndex) {
		GameObject * lightSourceGameObject = new GameObject;
		std::string const vertexLightingShaderPath{ shadersFolderPath + std::string{ "/vertex_shader.glsl" } };
		std::string const fragmentLightingShaderPath{ shadersFolderPath + std::string{ "/fragment_lamp_shader.glsl" } };
		std::weak_ptr<Material> material = lightSourceGameObject->addComponent<Material>();
		if (auto materialShared = material.lock()) {
			const int numberOfTextures = 2;
			materialShared->initMaterial(vertexLightingShaderPath, fragmentLightingShaderPath);
		}

		std::weak_ptr<Renderer> rendererWeak = lightSourceGameObject->addComponent<Renderer>();
		if (auto rendererShared = rendererWeak.lock()) {
			VertexData vertexData{ verticesUV, (int)(sizeof(verticesUV) / sizeof(float)), indices, (int)sizeof(indices), true, false };
			rendererShared->initRenderer(vertexData);
		}

		std::weak_ptr<Transform> lightSourceTransformWeak = lightSourceGameObject->addComponent<Transform>();
		if (auto transformShared = lightSourceTransformWeak.lock()) {
			transformShared->setPosition(cubePositions[lightSourceIndex]);
			transformShared->setScale(Vector3{ 0.2F });
		}

		return lightSourceGameObject;
	}

	void createBoxObjects(
		std::string const & specularMapTexturePath, std::string const & diffuseMapTexturePath, std::string const & vertexShaderPath, std::string const & fragmentShaderPath,
		int numberOfBoxes, std::weak_ptr<Transform> cameraTransformWeak, std::weak_ptr<Transform> lightSourceTrnasformWeak) {

		GameObject * boxObjects = new GameObject[numberOfBoxes];

		for (int i = 0; i < numberOfBoxes; ++i) {
			std::weak_ptr<Material> material = boxObjects[i].addComponent<Material>();
			setRandomColors(material);

			if (auto materialShared = material.lock()) {
				materialShared->initMaterial(vertexShaderPath, fragmentShaderPath);

				auto shaderProgramWeak = materialShared->getShaderProgram();
				if (auto shaderProgramShared = shaderProgramWeak.lock()) {
					shaderProgramShared->use();
					shaderProgramShared->setVec3("lightColor", 1.5F, 1.6F, 1.89F);

					if (auto lightSourceTransformShared = lightSourceTrnasformWeak.lock()) {
						auto lightPos = lightSourceTransformShared->getPosition();
						shaderProgramShared->setVec3("lightPos", lightPos.x, lightPos.y, lightPos.z);
					}

					if (auto cameraTransformShared = cameraTransformWeak.lock()) {
						auto cameraPos = cameraTransformShared->getPosition();
						shaderProgramShared->setVec3("cameraPos", cameraPos.x, cameraPos.y, cameraPos.z);
					}
				}

				materialShared->setDiffuseMap(diffuseMapTexturePath);
				materialShared->setSpecularMap(specularMapTexturePath);
			}

			if (i % 2) {
				boxObjects[i].addComponent<Rotator>();
			}

			std::weak_ptr<Renderer> renderer = boxObjects[i].addComponent<Renderer>();
			if (auto rendererShared = renderer.lock()) {
				VertexData vertexData{ verticesUVNormals, (int)(sizeof(verticesUVNormals) / sizeof(float)), indices, (int)(sizeof(indices) / sizeof(int)), true, true };
				rendererShared->initRenderer(vertexData);
			}

			std::weak_ptr<Transform> transform = boxObjects[i].addComponent<Transform>();
			if (auto transformShared = transform.lock()) {
				transformShared->setPosition(cubePositions[i]);
			}
		}
	}

	void initScene(std::string const & executablePath) {
		GameObject * const cameraGameObject = new GameObject();
		auto cameraTransformWeak = cameraGameObject->addComponent<Transform>();
		auto cameraWeak = cameraGameObject->addComponent<Camera>();

		if (auto cameraShared = cameraWeak.lock()) {
			cameraShared->initCamera(45.0F, SCR_WIDTH, SCR_HEIGHT);
			Camera::setMainCamera(cameraShared);
		}

		std::string const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
		std::string const shadersFolderPath{ rootPath + std::string{"/../../../Source/Core/ShaderFiles"} };
		std::string const vertexShaderPath{ shadersFolderPath + std::string{ "/vertex_lighting_shader.glsl" } };
		std::string const fragmentShaderPath{ shadersFolderPath + std::string{ "/fragment_lighting_shader.glsl" } };
		std::string const resourcesFolderPath{ rootPath + std::string{ "/../../../Resources/Resources" } };
		std::string const diffuseMapPath = resourcesFolderPath + std::string{ "/Art/container.png" };
		std::string const specularMapPath = resourcesFolderPath + std::string{ "/Art/specular_map_container.png" };
		std::string const texturePathArray[2]{
			resourcesFolderPath + std::string{ "/Art/wall.png" },
			resourcesFolderPath + std::string{ "/Art/awesomeface.png" }
		};

		constexpr int numberOfObjects = (sizeof(cubePositions) / sizeof(cubePositions[0]));
		GameObject * lightSourceGameObject = createLight(shadersFolderPath, texturePathArray, numberOfObjects - 1);

		int const numberOfBoxes = numberOfObjects - 1;
		std::weak_ptr<Transform> lightSourceTransformWeak = lightSourceGameObject->getComponent<Transform>();
		createBoxObjects(specularMapPath, diffuseMapPath, vertexShaderPath, fragmentShaderPath, numberOfBoxes, cameraTransformWeak, lightSourceTransformWeak);
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
}
