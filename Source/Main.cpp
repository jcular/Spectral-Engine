#include <iostream>
#include <memory>

#include "Core/Utility/Initializers.h"
#include "Core/Components/Material.h"
#include "Core/Components/Renderer.h"
#include "Core/Utility/CameraInputHandler.h"

#include "Core/Utility/Vertices.h"
#include "Core/Components/Renderer.h"


int main(int argc, char** argv) {
	auto window = setupWindow();

	if (window == nullptr) {
		return -1;
	}

	glfwSetCursorPosCallback(window, CameraInputHandler::mouse_callback);
	initScene(argv[0]);

	glEnable(GL_DEPTH_TEST);

	float lastFrame = static_cast<float>(glfwGetTime());

	while (!glfwWindowShouldClose(window)) {
		float currentFrame = static_cast<float>(glfwGetTime());
		float deltaTime = currentFrame - lastFrame;
		GameObject::updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		CameraInputHandler::processCameraInput(window, deltaTime);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		float oscilationFactor = (sin(currentFrame) / 2) + 0.5F;
		float color[3] = { 1.0F - oscilationFactor, oscilationFactor, 0.5 };

		std::vector<GameObject *> gameObjectCollection = GameObject::getGameObjectCollection();
		for (auto const & gameObject : gameObjectCollection) {
			auto rendererWeak = gameObject->getComponent<Renderer>();
			if (auto rendererShared = rendererWeak.lock()) {
				rendererShared->renderObject();
			}
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glfwTerminate();

	return 0;
}
