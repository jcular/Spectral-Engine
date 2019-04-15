#pragma once

namespace sp {
	class Vector2;

	class Vector3 {
	public:
		static float const dot(Vector3 const & vec1, Vector3 const & vec2);
		static Vector3 const cross(Vector3 const & vec1, Vector3 const & vec2);

	public:
		Vector3();
		Vector3(Vector3 const & vector) = default;
		Vector3(Vector2 const & vector);
		Vector3(float val);
		Vector3(float const x, float const y, float const z);

	public:
		float x, y, z;
		Vector3 operator-() const;
		Vector3 operator+(Vector3 const & vector) const;
		Vector3 operator-(Vector3 const & vector) const;
		Vector3 operator*(float const realNumber) const;
		Vector3 operator+=(Vector3 const & vector);
		Vector3 operator-=(Vector3 const & vector);

	public:
		Vector3 normalized() const;
		float const length() const;
	};

	Vector3 operator*(float const realNumber, Vector3 const & vector);
}