#pragma once

#include "Utility/Math/Vector3.h"

namespace sp {
	class Vector2 {
	public:
		Vector2();
		Vector2(float const x, float const y);
		Vector2(Vector3 const & vector3);

	public:
		Vector2 operator+(Vector2 const & vector2) const;
		Vector2 operator-(Vector2 const & vector2) const;
		Vector2 operator-() const;

	public:
		float x;
		float y;
	};
}