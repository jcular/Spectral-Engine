#include "Degree.h"
#include "Radian.h"
#include "SpMath.h"

namespace sp {
	Radian::Radian() : value{ 0.0F } {
	}

	Radian::Radian(float const value) : value{ value } {
	}

	Radian::Radian(Degree const degree) {
		this->value = degree.getValueRadians();
	}
}
