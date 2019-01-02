#include "Transform.h"



Transform::Transform(GameObject * const gameObjectOwner) :
	GameObjectComponent(gameObjectOwner),
	position{ 0.0F },
	scale{ 1.0F } {
}

glm::vec3 const Transform::getPosition() const {
	return this->position;
}

void Transform::setPosition(glm::vec3 const & position) {
	this->position = position;
}

glm::mat4x4 const Transform::getTransformMatrix() const {
	glm::mat4x4 transformMatrix{ 1.0F };
	transformMatrix = glm::translate(transformMatrix, this->position);
	transformMatrix = glm::rotate(transformMatrix, this->rotationEuler.x, glm::vec3{ 1.0F, 0.0F, 0.0F });
	transformMatrix = glm::rotate(transformMatrix, this->rotationEuler.y, glm::vec3{ 0.0F, 1.0F, 0.0F });
	transformMatrix = glm::rotate(transformMatrix, this->rotationEuler.z, glm::vec3{ 0.0F, 0.0F, 1.0F });
	transformMatrix = glm::scale(transformMatrix, this->scale);

	return transformMatrix;
}

glm::vec3 Transform::getRotationEuler() const {
	return this->rotationEuler;
}

void Transform::setRotationEuler(glm::vec3 const & rotation) {
	this->rotationEuler = rotation;
}

void Transform::setScale(glm::vec3 const & scale) {
	this->scale = scale;
}

glm::mat4x4 const Transform::getTranslationMatrix() const {
	glm::mat4x4 mat{ 1.0F };
	return glm::translate(mat, this->position);
}
