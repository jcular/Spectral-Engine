#include "Utility/Math/Degree.h"
#include "gtest/gtest.h"
#include "Utility/Math/SpMath.h"

namespace sp
{
	namespace test {
		TEST(test_Degree_getValueDegree) {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueDegree = degree.getValueDegrees();
			
			// Assert
			ASSERT_EQ(initialValueDegree, resultValueDegree);
		}

		TEST(test_Degree_getValueRadian) {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueRadians = degree.getValueRadians();

			// Assert
			float const expectedValueRadians = initialValueDegree * PI / 180.0F;
			ASSERT_EQ(expectedValueRadians, resultValueRadians);
		}
	}
}