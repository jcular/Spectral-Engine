#include "CameraInputHandler.h"
#include "Components/Camera.h"
#include "Components/Transform.h"
#include "GameObject/GameObject.h"

namespace sp {
	glm::vec3 CameraInputHandler::worldUp = glm::vec3(0.0F, 1.0F, 0.0F);
	bool CameraInputHandler::firstMouse = true;
	double CameraInputHandler::lastX;
	double CameraInputHandler::lastY;
	double CameraInputHandler::yaw = 0.0F;
	double CameraInputHandler::pitch = 0.0F;
	bool CameraInputHandler::first = false;

	void CameraInputHandler::mouse_callback(GLFWwindow * window, double xpos, double ypos) {
		if (firstMouse) {
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		double xOffset = xpos - lastX;
		double yOffset = lastY - ypos;

		lastX = xpos;
		lastY = ypos;

		double sensitivity = 0.05F;

		xOffset *= sensitivity;
		yOffset *= sensitivity;

		yaw += xOffset;
		pitch += yOffset;

		if (pitch > 89.0F) {
			pitch = 89.0F;
		}
		if (pitch < -89.0F) {
			pitch = -89.0F;
		}


		auto cameraShared = Camera::getMainCamera();
		auto transformWeak = cameraShared->getGameObject()->getComponent<Transform>();

		if (auto transformShared = transformWeak.lock()) {
			transformShared->setRotationEuler(glm::vec3{ pitch, yaw, 0.0F });
			first = true;
		}
	}

	void CameraInputHandler::processCameraInput(GLFWwindow *window, float deltaTime) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, true);
		}

		float cameraSpeed = 1.0F;
		auto mainCameraShared = Camera::getMainCamera();
		auto transformWeak = mainCameraShared->getGameObject()->getComponent<Transform>();
		auto cameraFront = mainCameraShared->getFront();

		if (auto transformShared = transformWeak.lock()) {
			glm::vec3 position = transformShared->getPosition();

			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
				position += cameraSpeed * cameraFront * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
				position -= cameraSpeed * cameraFront * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
				position -= cameraSpeed * glm::normalize(glm::cross(cameraFront, worldUp)) * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
				position += cameraSpeed * glm::normalize(glm::cross(cameraFront, worldUp)) * deltaTime;
			}

			transformShared->setPosition(position);
		}
	}
}
