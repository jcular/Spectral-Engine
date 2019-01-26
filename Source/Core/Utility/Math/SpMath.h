#pragma once

namespace sp {
	class Radian;
	class Degree;

	#define PI 3.14159265358979323846F

	float const sin(Radian const rad);
	float const sin(Degree const degree);
	float const cos(Radian const rad);
	float const cos(Degree const degree);
	float const tan(Radian const radian);
	float const tan(Degree const degree);
	float const sqrt(float const number);
}