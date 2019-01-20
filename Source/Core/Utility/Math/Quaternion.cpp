#include "Quaternion.h"
#include "Vector3.h"

namespace sp {
	Quaternion::Quaternion() : x{ 0.0F }, y{ 0.0F }, z{ 0.0F }, w{ 0.0F } {
	}

	Quaternion::Quaternion(float const x, float const y, float const z, float const w) : x{ x }, y{ y }, z{ z }, w{ w } {
	}

	Quaternion::Quaternion(Vector3 const & vector) : x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ 0.0F } {
	}
}