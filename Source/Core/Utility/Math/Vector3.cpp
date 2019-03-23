#include "Utility/Math/Vector3.h"
#include "Utility/Math/SpMath.h"

namespace sp {
	float const sp::Vector3::dot(Vector3 const & vec1, Vector3 const & vec2) {
		return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	}

	Vector3 const Vector3::cross(Vector3 const & vec1, Vector3 const & vec2) {
		return Vector3{
			(vec1.y * vec2.z) - (vec1.z * vec2.y),
			(vec1.z * vec2.x) - (vec1.x * vec2.z),
			(vec1.x * vec2.y) - (vec1.y * vec2.x)
		};
	}

	Vector3::Vector3() : x{ 0.0F }, y{ 0.0F }, z{ 0.0F } {

	}

	Vector3::Vector3(float val) : x{ val }, y{ val }, z{ val } {
	}

	Vector3::Vector3 (float const x, float const y, float const z) : x{ x }, y{ y }, z{ z } {
	}

	Vector3 Vector3::operator-() const {
		return Vector3{ -x, -y, -z };
	}

	Vector3 Vector3::operator+(Vector3 const & vector) const {
		return Vector3{
			this->x + vector.x,
			this->y + vector.y,
			this->z + vector.z
		};
	}

	Vector3 Vector3::operator-(Vector3 const & vector) const {
		return Vector3{
			this->x - vector.x,
			this->y - vector.y,
			this->z - vector.z
		};
	}

	Vector3 Vector3::operator*(float const realNumber) const {
		return Vector3{
			this->x * realNumber,
			this->y * realNumber,
			this->z * realNumber
		};
	}

	Vector3 Vector3::operator+=(Vector3 const & vector) {
		*this = (*this) + vector;

		return *this;
	}

	Vector3 Vector3::operator-=(Vector3 const & vector) {
		*this = (*this) - vector;

		return *this;
	}

	Vector3 Vector3::normalized() const {
		float const length = this->length();

		return Vector3{
			this->x / length,
			this->y / length,
			this->z / length
		};
	}

	float const Vector3::length() const {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	Vector3 operator*(float const realNumber, Vector3 const & vector) {
		return Vector3{
			vector.x * realNumber,
			vector.y * realNumber,
			vector.z * realNumber
		};
	}
}