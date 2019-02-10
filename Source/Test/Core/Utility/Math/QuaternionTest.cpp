#include "gtest/gtest.h"
#include "Utility/Math/Quaternion.h"
#include "Utility/Math/Vector3.h"
#include "Utility/Math/SpMath.h"

namespace sp {
	namespace test {
		TEST(test_Quaternion_multiplicationWithQuat) {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Quaternion{ 0.4F, 1.0F, 0.0F, 12.2F });

			// Assert
			Quaternion const expectedResult{ 1.4F, 137.66F, 23.88F, -10.1F };
			const float epsilon = 0.001F;
			ASSERT_TRUE(abs(result.y - expectedResult.y) <= epsilon);
			ASSERT_TRUE(abs(result.x - expectedResult.x) <= epsilon);
			ASSERT_TRUE(abs(result.z - expectedResult.z) <= epsilon);
			ASSERT_TRUE(abs(result.w - expectedResult.w) <= epsilon);
		}


		TEST(test_Quaternion_multiplicationWithVec3) {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Vector3{ 0.4F, 1.0F, 1.2F });

			// Assert
			Quaternion const expectedResult{ 11.18F, 0.66F, -4.06F, -14.08F };
			const float epsilon = 0.01F;
			ASSERT_TRUE(abs(result.x - expectedResult.x) <= epsilon);
			ASSERT_TRUE(abs(result.y - expectedResult.y) <= epsilon);
			ASSERT_TRUE(abs(result.z - expectedResult.z) <= epsilon);
			ASSERT_TRUE(abs(result.w - expectedResult.w) <= epsilon);
		}
	}
}