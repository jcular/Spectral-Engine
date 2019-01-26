#include "Utility/Math/LinearTransformations.h"
#include "Utility/Math/Matrix4x4.h"

namespace sp {
	Matrix4x4 const getPerspectiveMat(Degree const fov, float const aspect, float const far, float const near) {
		float const frustumDepth = far - near;
		float const oneOverDepth = 1 / frustumDepth;

		Matrix4x4 result;
		result[1][1] = 1 / tan(fov / 2.0F);
		result[0][0] = -result[1][1] / aspect;
		result[2][2] = far * oneOverDepth;
		result[3][2] = (-far * near) * oneOverDepth;
		result[2][3] = 1;
		result[3][3] = 0;

		return result;
	}
}
