#include <iostream>
#include <memory>

#include "Core/Utility/Initializers.h"
#include "Core/Utility/ResourcesPathProvider.h"
#include "Core/Components/Interface/IRenderer.h"
#include "Core/Components/Material.h"
#include "Core/Components/Renderer.h"
#include "Core/Utility/CameraInputHandler.h"

#include "Core/Utility/Vertices.h"
#include "Core/Components/Renderer.h"
#include "Utility/Math/Vector3.h"


int main(int argc, char** argv) {
	auto window = sp::setupWindow();

	if (window == nullptr) {
		return -1;
	}

	std::cout << sizeof(sp::Vector3) << std::endl;

	glfwSetCursorPosCallback(window, sp::CameraInputHandler::mouse_callback);

	std::string const executablePath{ argv[0] };
	std::string const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
	sp::ResourcesPathProvider::initializePaths(rootPath);
	sp::initScene(argv[0]);

	glEnable(GL_DEPTH_TEST);

	float lastFrame = static_cast<float>(glfwGetTime());

	while (!glfwWindowShouldClose(window)) {
		float currentFrame = static_cast<float>(glfwGetTime());
		float deltaTime = currentFrame - lastFrame;
		sp::GameObject::updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, true);
		}

		sp::CameraInputHandler::processCameraInput(window, deltaTime);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		float oscilationFactor = (sin(currentFrame) / 2) + 0.5F;
		float color[3] = { 1.0F - oscilationFactor, oscilationFactor, 0.5 };

		std::vector<sp::GameObject *> gameObjectCollection = sp::GameObject::getGameObjectCollection();
		for (auto const & gameObject : gameObjectCollection) {
			auto rendererWeak = gameObject->getComponent<sp::IRenderer>();
			if (auto rendererShared = rendererWeak.lock()) {
				rendererShared->render();
			}
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glfwTerminate();

	return 0;
}
