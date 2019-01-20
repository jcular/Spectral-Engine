#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3.h"

namespace sp {
	inline const Matrix4x4 Translate(Matrix4x4 const & mat, Vector3 const & translation) {
		Matrix4x4 translationMat;
		translationMat[0][3] = translation.x;
		translationMat[1][3] = translation.y;
		translationMat[2][3] = translation.z;

		return translationMat * mat;
	}
}
