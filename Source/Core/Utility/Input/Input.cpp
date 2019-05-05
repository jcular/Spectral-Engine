#include <memory>
#include <GLFW/glfw3.h>

#include "Input.h"
#include "SpWindow.h"
#include "MouseInputManager.h"
#include "KeyInputManager.h"

std::unique_ptr<sp::MouseInputManager> sp::Input::mouseInputManagerUnique;
std::unique_ptr<sp::KeyInputManager> sp::Input::keyInputManagerUnique;

void sp::Input::init() {
	Input::mouseInputManagerUnique = std::make_unique<MouseInputManager>();

	GLFWwindow * window = SpWindow::getInstance()->getConcreteWindow();
	glfwSetCursorPosCallback(window, 
		[](auto window, auto xpos, auto ypos) {
			Input::mouseInputManagerUnique->updateMousePos((float)xpos, (float)ypos); 
		});
		
	Input::keyInputManagerUnique = std::unique_ptr<KeyInputManager>(new KeyInputManager{ window });
}

bool const sp::Input::keyDown(KeyCode keyCode) {
	return Input::keyInputManagerUnique->keyPressed(keyCode);
}

sp::Vector2 const sp::Input::mouseAxis() {
	return Vector2{ Input::mouseInputManagerUnique->xDelta, Input::mouseInputManagerUnique->yDelta };
}
