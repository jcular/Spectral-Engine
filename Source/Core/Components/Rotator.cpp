#include "Core/Components/Rotator.h"

#include "Core/GameObject/GameObject.h"
#include "Core/Components/Transform.h"

namespace sp {
	Rotator::Rotator(GameObject * const gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Rotator::update(float deltaTime) {
		this->passedTime += deltaTime;
		auto transformComponentWeak = gameObjectOwner->getComponent<Transform>();
		if (auto transformComponentShared = transformComponentWeak.lock()) {
			transformComponentShared->setRotationEuler(Vector3{ 0.0F, sin(this->passedTime * (0.2F)) * 360.0F, 0.0F });
		}
	}
}
