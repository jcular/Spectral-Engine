#include "SpMath.h"

namespace sp {
	class Radian;

	class Degree {
	public:
		Degree();
		Degree(Degree const & degree) = default;
		Degree(float value);
		Degree(Radian radian);

	public:
		constexpr float const getValueDegrees() const {
			return this->value;
		}

		constexpr float const getValueRadians() const {
			return this->value * PI / 180.0F;
		}

	private:
		float value;
	};
}