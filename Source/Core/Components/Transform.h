#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GameObjectComponent.h"

class Transform : public GameObjectComponent {
public:
	Transform(GameObject * const gameObjectOwner);
	glm::vec3 const getPosition() const;
	void setPosition(glm::vec3 const & positon);
	glm::mat4x4 const getTransformMatrix() const;
	glm::vec3 getRotationEuler() const;
	void setRotationEuler(glm::vec3 const & rotation);
	void setScale(glm::vec3 const & scale);

private:
	glm::mat4x4 const getTranslationMatrix() const;
	glm::vec3 position;
	glm::vec3 rotationEuler;
	glm::vec3 scale;
};

