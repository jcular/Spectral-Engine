#pragma once

#include "Utility/Input/KeyCode.h"
#include "Utility/Math/Vector2.h"

namespace sp {
	class Input {
	private:
		Input() = delete;

	public:
		static bool const keyDown(KeyCode keyCode);
		static Vector2 const mouseAxis();
	};
}
