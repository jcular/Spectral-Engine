#include "gtest/gtest.h"
#include "Utility/Math/LinearTransformations.h"
#include "Utility/Math/Matrix4x4.h"
#include "Utility/Math/Vector3.h"

namespace sp {
	namespace test {
		TEST(test_translate) {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const translation{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = translate(transformation, translation);

			// assert
			float const epsilon = 0.001;
			for (int i = 0; i < 16; ++i) {
				float expectedValue;
				if (i == 3) {
					expectedValue = translation.x;
				}
				else if (i == 7) {
					expectedValue = translation.y;
				}
				else if (i == 11) {
					expectedValue = translation.z;
				}
				else {
					expectedValue = transformation.getValuePtr()[i];
				}

				float const * values = resultMatrix.getValuePtr();
				ASSERT_TRUE(abs(values[i] - expectedValue) < epsilon);
			}
		}

		TEST(test_scale) {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const scaleVector{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = scale(transformation, scaleVector);

			// assert
			float const epsilon = 0.001;
			float const * startingValues = transformation.getValuePtr();
			for (int i = 0; i < 16; ++i) {
				float expectedValue;
				if (i == 0) {
					expectedValue = startingValues[i] * scaleVector.x;
				}
				else if (i == 5) {
					expectedValue = startingValues[i] * scaleVector.y;
				}
				else if (i == 10) {
					expectedValue = startingValues[i] * scaleVector.z;
				}
				else {
					expectedValue = transformation.getValuePtr()[i];
				}

				float const * resultValues = resultMatrix.getValuePtr();
				ASSERT_TRUE(abs(resultValues[i] - expectedValue) < epsilon);
			}
		}
	}
}