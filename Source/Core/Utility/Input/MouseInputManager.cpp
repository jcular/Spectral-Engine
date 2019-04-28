#include "MouseInputManager.h"

sp::Vector2 const sp::MouseInputManager::getMouseDelta() {
	return Vector2{ this->xDelta, this->yDelta };
}

sp::MouseInputManager::MouseInputManager(SpWindow const * const window) : window{ window } {
}

void sp::MouseInputManager::updateMousePos(float const xPosition, float const yPosition) {
	this->xDelta = this->xPosition - xPosition;
	this->yDelta = this->yPosition - yPosition;

	this->xPosition = xPosition;
	this->yPosition = yPosition;
}
