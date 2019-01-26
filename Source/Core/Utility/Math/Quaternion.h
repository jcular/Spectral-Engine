#pragma once

namespace sp {
	class Vector3;

	class Quaternion {
		friend Quaternion operator*(Vector3 const & vec, Quaternion const & quat);

	public:
		Quaternion();
		Quaternion(Quaternion const & quaternion) = default;
		Quaternion(float const x, float const y, float const z, float const w);
		Quaternion(Vector3 const & vec3);

	public:
		Quaternion operator*(Quaternion const & quaternion);
		Quaternion operator*(Vector3 const & vec3);

	public:
		float const x, y, z, w;
	};
}