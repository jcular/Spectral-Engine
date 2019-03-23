#include "Components/GameObjectComponent.h"

namespace sp {
	GameObjectComponent::GameObjectComponent(GameObject * const gameObjectOwner) :
		gameObjectOwner{ gameObjectOwner } {
	}

	void GameObjectComponent::update(float const deltaTime) {
	}

	GameObject const * const GameObjectComponent::getGameObject() const {
		return this->gameObjectOwner;
	}

	GameObjectComponent::~GameObjectComponent() {
	}
}
