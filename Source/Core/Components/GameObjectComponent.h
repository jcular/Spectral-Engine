#pragma once

#include "Core/GameObject/GameObject.h"

class GameObject;

class GameObjectComponent {
public:
	GameObjectComponent(GameObject * const gameObject);
	virtual void update(float const deltaTime);
	GameObject const * const getGameObject();
	virtual ~GameObjectComponent();

protected:
	GameObject * gameObjectOwner;
};
