#pragma once

namespace sp {
	class GameObject;

	class GameObjectComponent {
	public:
		GameObjectComponent(GameObject * const gameObject);
		virtual void update(float const deltaTime);
		GameObject const * const getGameObject() const;
		virtual ~GameObjectComponent();

	protected:
		GameObject * gameObjectOwner;
	};
}
