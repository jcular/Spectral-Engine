#include "Utility/Math/LinearTransformations.h"
#include "Utility/Math/Matrix4x4.h"

namespace sp {
	Matrix4x4 const getPerspectiveMat(Degree const fov, float const aspect, float const far, float const near) {
		float const frustumDepth = near - far;

		Matrix4x4 result;
		result[1][1] = 1.0F / tan(fov / 2.0F);
		result[0][0] = result[1][1] / aspect;
		result[2][2] = -(far + near) / frustumDepth;
		result[3][2] = (-2 * far * near) / frustumDepth;
		result[2][3] = -1.0F;
		result[3][3] = 0;

		result = result.transposed();
		return result;
	}
}
