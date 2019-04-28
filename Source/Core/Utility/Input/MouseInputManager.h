#pragma once

#include "Utility/Math/Vector2.h"

namespace sp {
	class SpWindow;

	class MouseInputManager {
		friend class Input;

	public:
		Vector2 const getMouseDelta();

	private:
		MouseInputManager(SpWindow const * const window);

	private:
		void updateMousePos(float const xPosition, float const yPosition);

	private:
		SpWindow const * const window;
		float xPosition;
		float yPosition;
		float xDelta;
		float yDelta;
	};
}
