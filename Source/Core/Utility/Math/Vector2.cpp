#include "Vector2.h"

sp::Vector2::Vector2() : x{ 0.0F }, y{ 0.0F } {
}

sp::Vector2::Vector2(float const x, float const y) : x{ x }, y{ y } {
}

sp::Vector2::Vector2(Vector3 const & vector3) : x{ vector3.x }, y{ vector3.y } {
}

sp::Vector2 sp::Vector2::operator+(Vector2 const & vector2) const
{
	return Vector2{ this->x + vector2.x, this->y + vector2.y };
}

sp::Vector2 sp::Vector2::operator-(Vector2 const & vector2) const
{
	return Vector2{ this->x - vector2.x, this->y - vector2.y };
}

sp::Vector2 sp::Vector2::operator-() const
{
	return Vector2{ -this->x, -this->y };
}
