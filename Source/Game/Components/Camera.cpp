#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"
#include "Game/Components/Camera.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Transform.h"

namespace sp {
	std::shared_ptr<Camera> Camera::mainCamera;

	Camera::Camera(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Camera::initCamera(Degree fov, int screenWidth, int screenHeight) {
		this->fov = fov;
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
	}

	Matrix4x4 Camera::getViewMatrix() {
		auto transformWeak = this->gameObjectOwner->getComponent<Transform>();

		if (auto transformShared = transformWeak.lock()) {
			Vector3 const worldUp{ 0.0F, 1.0F, 0.0f };
			Vector3 forward = this->getForward();
			Vector3 right = Vector3::cross(forward, worldUp).normalized();
			Vector3 up = Vector3::cross(right, forward).normalized();
			Vector3 position = transformShared->getPosition();
			auto lookAt = getLookAtMatrix(forward, up, position);
			return lookAt;
		}

		return Matrix4x4{};
	}

	Matrix4x4 Camera::getProjectionMatrix() {
		float aspect = static_cast<float>(this->screenWidth) / this->screenHeight;
		return sp::getPerspectiveMat(this->fov, aspect, 0.1F, 100.0F);
	}

	Vector3 const Camera::getForward() const {
		float x, y, z;

		auto transformWeak = this->gameObjectOwner->getComponent<Transform>();
		if (auto transformShared = transformWeak.lock()) {
			Vector3 rotation = transformShared->getRotationEuler();
			Degree rotX{ rotation.x };
			Degree rotY{ rotation.y };
			x = static_cast<float>(cos(rotX) * cos(rotY));
			y = static_cast<float>(sin(rotX));
			z = static_cast<float>(cos(rotX) * sin(rotY));
		}

		return Vector3{ x, y, z };
	}

	std::shared_ptr<Camera> Camera::getMainCamera() {
		return mainCamera;
	}

	void Camera::setMainCamera(std::shared_ptr<Camera> const camera) {
		mainCamera = camera;
	}
}

