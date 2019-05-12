#pragma once

#include<memory>

#include "Utility/Input/KeyCode.h"
#include "Utility/Math/Vector2.h"

namespace sp {
	class MouseInputManager;
	class KeyInputManager;

	class Input {
	private:
		Input() = delete;

	public:
		static void init();
		static bool const keyDown(KeyCode keyCode);
		static Vector2 const mouseAxis();
		static void update();

	private:
		static std::unique_ptr<MouseInputManager> mouseInputManagerUnique;
		static std::unique_ptr<KeyInputManager> keyInputManagerUnique;
	};
}
