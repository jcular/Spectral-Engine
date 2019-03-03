#include "Character.h"

sp::Character::Character(
	unsigned int const textureId,
	unsigned int const width,
	unsigned int const height,
	unsigned int const bitmapLeft,
	unsigned int const bitmapTop,
	unsigned int const advance) :
	textureId{ textureId }, width{ width }, height{ height }, bitmapLeft{ bitmapLeft }, bitmapTop{ bitmapTop }, advance{ advance } {
}
