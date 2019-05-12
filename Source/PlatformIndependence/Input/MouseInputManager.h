#pragma once

#include "Core/Math/Vector2.h"

namespace sp {
	class MouseInputManager {
		friend class Input;

	public:
		MouseInputManager() = default;

	public:
		void update();
		void updateMousePos(float const xPosition, float const yPosition);

	private:
		float xPosition = 0.0F;
		float yPosition = 0.0F;
		float xDelta = 0.0F;
		float yDelta = 0.0F;
		bool updated = false;
	};
}
