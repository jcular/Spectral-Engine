#include <cmath>

#include "Degree.h"
#include "Radian.h"
#include "SpMath.h"

namespace sp {
	float const sin(Radian const rad) {
		return std::sin(rad.getValueRadians());
	}
	float const sin(Degree const degree) {
		return std::sin(degree.getValueRadians());
	}
	float const cos(Radian const rad) {
		return std::cos(rad.getValueRadians());
	}
	float const cos(Degree const degree) {
		return std::cos(degree.getValueRadians());
	}
}
