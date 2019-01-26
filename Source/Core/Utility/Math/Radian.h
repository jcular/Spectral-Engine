#pragma once

#include "Utility/Math/SpMath.h"

namespace sp {
	class Degree;

	class Radian {
	public:
		Radian();
		Radian(Radian const & radian) = default;
		Radian(float const value);
		Radian(Degree const degree);

	public:
		constexpr float const getValueRadians() const {
			return this->value;
		}

		constexpr float const getVlueDegrees() const {
			return this->value * 180.0F / PI;
		}

	private:
		float value;
	};
}