#include "gtest/gtest.h"
#include "Utility/Math/Radian.h"
#include "Utility/Math/SpMath.h"

namespace sp {
	namespace test {
		TEST(Radian, getValueRadian) {
			// Arrange
			float const initialValueRadian{ 2.12F };
			Radian const radian{ initialValueRadian };

			// Act
			float const resultValueRadians = radian.getValueRadians();

			// Assert
			ASSERT_EQ(initialValueRadian, resultValueRadians);
		}

		TEST(Radian, getValueDegree) {
			// Arrange
			float const initialValueRadian{ 5.1F };
			Radian const radian{ initialValueRadian };

			// Act
			float const resultValueDegree = radian.getVlueDegrees();

			// Assert
			float const expectedValueDegree = initialValueRadian * 180.0F / PI;
			ASSERT_EQ(expectedValueDegree, resultValueDegree);
		}
	}
}