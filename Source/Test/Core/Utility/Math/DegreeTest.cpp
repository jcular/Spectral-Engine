#include "Core/Math/Degree.h"
#include "gtest/gtest.h"
#include "Core/Math/SpMath.h"

namespace sp
{
	namespace test {
		TEST(Degree, getValueDegree) {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueDegree = degree.getValueDegrees();
			
			// Assert
			ASSERT_EQ(initialValueDegree, resultValueDegree);
		}

		TEST(Degree, getValueRadian) {
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