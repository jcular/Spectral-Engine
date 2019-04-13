#include "Utility/Math/LinearTransformations.h"
#include "Utility/Math/Matrix4x4.h"

namespace sp {
	Matrix4x4 const getPerspectiveMat(Degree const fov, float const aspect, float const far, float const near) {
		Matrix4x4 result;
		result[1][1] = 1.0F / tan(fov / 2.0F);
		result[0][0] = result[1][1] / aspect;

		float const frustumDepth = near - far;
		result[2][2] = -(far + near) / frustumDepth;
		result[2][3] = (-2 * far * near) / frustumDepth;
		result[3][2] = -1.0F;
		result[3][3] = 0;

		return result;
	}
	Matrix4x4 const getOrthographicMat(float const left, float const right, float const bottom, float const top, float const zNear, float const zFar) {
		Matrix4x4 result;
		result[0][0] = 2.0F / (right - left);
		result[1][1] = 2.0F / (top - bottom);
		result[2][2] = -2 / (zFar - zNear);
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -(zFar + zNear) / (zFar - zNear);
		result[3][3] = 1;

		return result;
	}
}
