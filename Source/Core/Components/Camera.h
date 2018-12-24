#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

#include "Core/GameObject/GameObject.h"
#include "Core/Components/GameObjectComponent.h"
#include "Core/Components/Transform.h"

class Camera : public GameObjectComponent {
public:
	static std::shared_ptr<Camera> getMainCamera();
	static void setMainCamera(std::shared_ptr<Camera> const mainCamera);

private:
	static std::shared_ptr<Camera> mainCamera;

public:
	Camera(GameObject * gameObjectOwner);
	void initCamera(float fov, int screenWidth, int screenHeight);
	glm::mat4x4 getViewMatrix();
	glm::mat4x4 getProjectionMatrix();
	glm::vec3 const getFront() const;

private:
	float fov;
	int screenWidth;
	int screenHeight;
};

