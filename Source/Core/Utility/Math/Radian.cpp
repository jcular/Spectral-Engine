#include "Degree.h"
#include "Radian.h"
#include "SpMath.h"

namespace sp {
	Radian::Radian() : value{ 0.0F } {
	}

	Radian::Radian(float value) : value{ value } {
	}

	Radian::Radian(Degree degree) {
		this->value = degree.getValueRadians();
	}
}
