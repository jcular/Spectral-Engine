#include "MouseInputManager.h"

void sp::MouseInputManager::update() {
	if (this->updated) {
		this->updated = true;
		return;
	}

	this->xDelta = 0.0F;
	this->yDelta = 0.0F;
}

void sp::MouseInputManager::updateMousePos(float const xPosition, float const yPosition) {
	this->xDelta = this->xPosition - xPosition;
	this->yDelta = this->yPosition - yPosition;

	this->xPosition = xPosition;
	this->yPosition = yPosition;
}
