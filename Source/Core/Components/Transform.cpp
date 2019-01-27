#include "Transform.h"
#include "Utility/Math/Degree.h"
#include "Utility/Math/LinearTransformations.h"
#include "Utility/Math/Matrix4x4.h"

namespace sp {
	Transform::Transform(GameObject * const gameObjectOwner) :
		GameObjectComponent(gameObjectOwner),
		position{ 0.0F },
		scaleVec{ 1.0F } {
	}

	Vector3 const Transform::getPosition() const {
		return this->position;
	}

	void Transform::setPosition(Vector3 const & position) {
		this->position = position;
	}

	Matrix4x4 const Transform::getTransformMatrix() const {
		Matrix4x4 transformMatrix;
		transformMatrix = scale(transformMatrix, this->scaleVec);
		transformMatrix = rotateX(transformMatrix, Degree{ this->rotationEuler.x });
		transformMatrix = rotateY(transformMatrix, Degree{ this->rotationEuler.y });
		transformMatrix = rotateZ(transformMatrix, Degree{ this->rotationEuler.z });
		transformMatrix = translate(transformMatrix, this->position);

		return transformMatrix;
	}

	Vector3 const Transform::getRotationEuler() const {
		return this->rotationEuler;
	}

	Vector3 const Transform::getDirection() const {
		Vector3 const eulerAngles = getRotationEuler();
		Degree const eulerX{ eulerAngles.x };
		Degree const eulerY{ eulerAngles.y };
		Vector3 const dir = Vector3{
			cos(eulerX) * cos(eulerY),
			sin(eulerX) * cos(eulerY),
			cos(eulerX) * sin(eulerY)
		};

		return dir;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		this->rotationEuler = rotation;
	}

	void Transform::setScale(Vector3 const & scale) {
		this->scaleVec = scale;
	}

	Matrix4x4 const Transform::getTranslationMatrix() const {
		Matrix4x4 mat;
		return translate(mat, this->position);
	}
}
