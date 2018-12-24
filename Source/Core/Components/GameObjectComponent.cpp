#include "GameObjectComponent.h"

GameObjectComponent::GameObjectComponent(GameObject * const gameObjectOwner) :
	gameObjectOwner{ gameObjectOwner } {
}

void GameObjectComponent::update(float const deltaTime) {
}

GameObject const * const GameObjectComponent::getGameObject() {
	return this->gameObjectOwner;
}

GameObjectComponent::~GameObjectComponent() {
}
