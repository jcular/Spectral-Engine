#include "MouseInputManager.h"

void sp::MouseInputManager::updateMousePos(float const xPosition, float const yPosition) {
	this->xDelta = this->xPosition - xPosition;
	this->yDelta = this->yPosition - yPosition;

	this->xPosition = xPosition;
	this->yPosition = yPosition;
}
