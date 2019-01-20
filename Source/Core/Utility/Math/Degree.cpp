#include "Degree.h"
#include "Radian.h"

namespace sp {
	Degree::Degree() : value{ 0.0F } {
	}

	Degree::Degree(float value) : value{ value } {
	}

	Degree::Degree(Radian radian) {
		this->value = radian.getValueRadians() * 180.0F / PI;
	}
}