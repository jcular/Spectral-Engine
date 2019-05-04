#include <memory>

#include "Input.h"
#include "SpWindow.h"
#include "MouseInputManager.h"

void sp::Input::init() {
	Input::mouseInputManagerUnique = std::make_unique<MouseInputManager>();

	SpWindow::getInstance()->registerMousePositionCallback(
		[](auto window, auto xpos, auto ypos) { Input::mouseInputManagerUnique->updateMousePos((float)xpos, (float)ypos); });
}

bool const sp::Input::keyDown(KeyCode keyCode) {
	return nullptr;
}

sp::Vector2 const sp::Input::mouseAxis() {
	return Vector2{ Input::mouseInputManagerUnique->xDelta, Input::mouseInputManagerUnique->yDelta };
}
