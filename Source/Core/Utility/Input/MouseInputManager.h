#pragma once

#include "Utility/Math/Vector2.h"

namespace sp {
	class MouseInputManager {
		friend class Input;

	private:
		MouseInputManager() = default;

	public:
		void updateMousePos(float const xPosition, float const yPosition);

	private:
		float xPosition;
		float yPosition;
		float xDelta;
		float yDelta;
	};
}
