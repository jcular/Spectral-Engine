namespace sp {
	class Vector3;

	class Quaternion {
	public:
		Quaternion();
		Quaternion(Quaternion const & quaternion) = default;
		Quaternion(float const x, float const y, float const z, float const w);
		Quaternion(Vector3 const & vector);

	public:
		float const x, y, z, w;
	};
}