#include <GameObject/GameObject.h>
#include <glm/glm.hpp>

#include "Rotator.h"
#include "Components/Transform.h"

Rotator::Rotator(GameObject * const gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
}

void Rotator::update(float deltaTime) {
	this->passedTime += deltaTime;
	auto transformComponentWeak = gameObjectOwner->getComponent<Transform>();
	if (auto transformComponentShared = transformComponentWeak.lock()) {
		transformComponentShared->setRotationEuler(glm::vec3{ 0.0F, glm::sin(this->passedTime * (0.003)) * 360.0F, 0.0F });
	}
}
