#pragma once

#include<memory>

#include "Utility/Input/KeyCode.h"
#include "Utility/Math/Vector2.h"

namespace sp {
	class MouseInputManager;

	class Input {
	private:
		Input() = delete;

	public:
		static void init();
		static bool const keyDown(KeyCode keyCode);
		static Vector2 const mouseAxis();

	private:
		static std::unique_ptr<MouseInputManager> mouseInputManagerUnique;
	};
}
