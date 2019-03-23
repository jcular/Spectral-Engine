#pragma once

#include "Utility/Math/Vector2.h"

namespace sp {
	class Character {
	public:
		Character(
			unsigned int const textureId,
			unsigned int const width,
			unsigned int const height,
			unsigned int const bitmapLeft,
			unsigned int const bitmapTop,
			unsigned int const advance);

	public:
		unsigned int const textureId;
		unsigned int const width;
		unsigned int const height;
		unsigned int const bitmapLeft;
		unsigned int const bitmapTop;
		unsigned int const advance;
	};
}
