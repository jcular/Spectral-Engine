#include "Camera.h"

std::shared_ptr<Camera> Camera::mainCamera;

Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
}

void Camera::initCamera(float fov, int screenWidth, int screenHeight) {
	this->fov = fov;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

glm::mat4x4 Camera::getViewMatrix() {
	auto transformWeak = this->gameObjectOwner->getComponent<Transform>();

	if (auto transformShared = transformWeak.lock()) {
		glm::vec3 const worldUp{ 0.0F, 1.0F, 0.0f };
		glm::vec3 front = this->getFront();
		glm::vec3 right = glm::cross(front, worldUp);
		glm::vec3 up = glm::cross(right, front);
		glm::vec3 position = transformShared->getPosition();
		return glm::lookAt(position, position + front, up);
	}

	return glm::mat4x4{ 1.0F };
}

glm::mat4x4 Camera::getProjectionMatrix() {
	float aspect = static_cast<float>(this->screenWidth) / this->screenHeight;
	return glm::perspective(this->fov, aspect, 0.1F, 100.0F);
}

glm::vec3 const Camera::getFront() const {
	glm::vec3 front;

	auto transformWeak = this->gameObjectOwner->getComponent<Transform>();
	if (auto transformShared = transformWeak.lock()) {
		glm::vec3 rotation = transformShared->getRotationEuler();
		front.x = static_cast<float>(cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y)));
		front.y = static_cast<float>(sin(glm::radians(rotation.x)));
		front.z = static_cast<float>(cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y)));
	}

	return front;
}

std::shared_ptr<Camera> Camera::getMainCamera() {
	return mainCamera;
}

void Camera::setMainCamera(std::shared_ptr<Camera> const camera) {
	mainCamera = camera;
}
