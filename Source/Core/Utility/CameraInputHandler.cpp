#include "CameraInputHandler.h"
#include "Components/Camera.h"
#include "Components/Transform.h"
#include "GameObject/GameObject.h"

namespace sp {
	Vector3 CameraInputHandler::worldUp{ 0.0F, 1.0F, 0.0F };
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
			transformShared->setRotationEuler(Vector3{ static_cast<float>(pitch), static_cast<float>(yaw), 0.0F });
			first = true;
		}
	}

	void CameraInputHandler::processCameraInput(GLFWwindow *window, float deltaTime) {
		float cameraSpeed = 1.0F;
		auto mainCameraShared = Camera::getMainCamera();
		auto transformWeak = mainCameraShared->getGameObject()->getComponent<Transform>();
		auto cameraFront = mainCameraShared->getForward();

		if (auto transformShared = transformWeak.lock()) {
			Vector3 position = transformShared->getPosition();

			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
				position += cameraSpeed * cameraFront * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
				position -= cameraSpeed * cameraFront * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
				position -= cameraSpeed * Vector3::cross(cameraFront, worldUp).normalized() * deltaTime;
			}
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
				position += cameraSpeed * Vector3::cross(cameraFront, worldUp).normalized() * deltaTime;
			}

			transformShared->setPosition(position);
		}
	}
}
