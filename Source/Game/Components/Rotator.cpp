#include "Game/Components/Rotator.h"

#include "Game/GameObject/GameObject.h"
#include "Game/Components/Transform.h"
#include "Core/Math/Radian.h"
#include "Core/Math/SpMath.h"

namespace sp {
	Rotator::Rotator(GameObject * const gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Rotator::update(float deltaTime) {
		this->passedTime += deltaTime;
		auto transformComponentWeak = gameObjectOwner->getComponent<Transform>();
		if (auto transformComponentShared = transformComponentWeak.lock()) {
			Radian radian(this->passedTime * (0.2F));
			transformComponentShared->setRotationEuler(Vector3{ 0.0F, sin(radian) * 360.0F, 0.0F });
		}
	}
}
