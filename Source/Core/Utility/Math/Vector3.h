namespace sp {
	class Vector3 {
	public:
		Vector3();
		Vector3(Vector3 const & vector) = default;
		Vector3(float val);
		Vector3(float const x, float const y, float const z);

	public:
		float const x, y, z;
	};
}