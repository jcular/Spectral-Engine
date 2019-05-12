#pragma once

#include "Core/Components/GameObjectComponent.h"
#include "Core/Math/Vector3.h"

namespace sp {
	 class CameraInputHandler : public GameObjectComponent {
	 public:
		 CameraInputHandler(GameObject * gameObject);

	 public:
		 void update(float deltaTime) override;

	 private:
	 	void processMouseInput();
	 	void processKeyInput(float deltaTime);
		
	 private:
	 	Vector3 worldUp{ 0.0F, 1.0F, 0.0F };
	 	double yaw = 0.0;
	 	double pitch = 0.0;
	 };
}
