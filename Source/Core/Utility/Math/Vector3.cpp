#include "Vector3.h"
namespace sp {
	Vector3::Vector3() : x{ 0.0F }, y{ 0.0F }, z{ 0.0F } {
	}

	Vector3::Vector3(float val) : x{ val }, y{ val }, z{ val } {
	}

	Vector3::Vector3 (float const x, float const y, float const z) : x{ x }, y{ y }, z{ z } {
	}
}