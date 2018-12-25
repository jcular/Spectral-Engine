#pragma once

#include <memory>
#include <vector>

class GameObjectComponent;

class GameObject {
public:
	GameObject();
	~GameObject();

public:
	template <typename T>
	std::weak_ptr<T> addComponent() {
		std::shared_ptr<T> component = std::make_shared<T>(this);
		this->components.push_back(std::static_pointer_cast<GameObjectComponent>(component));
		return std::weak_ptr<T>{ component };
	};

	template <typename T>
	std::weak_ptr<T> getComponent() const {
		for (auto const & comp : this->components) {
			std::shared_ptr<T> componentT = std::dynamic_pointer_cast<T>(comp);
			if (componentT != nullptr) {
				return std::weak_ptr<T>{ componentT };
			}
		}

		return std::weak_ptr<T>{};
	};

	void updateComponents(float const deltaTime);
	static void updateGameObjects(float const deltaTime);
	static std::vector<GameObject *> getGameObjectCollection();


private:
	std::vector<std::shared_ptr<GameObjectComponent>> components;
	static int getGameObjectIndex(GameObject *);
	static std::vector<GameObject *> gameObjectCollection;
};
