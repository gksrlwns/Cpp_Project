#include "pch.h"
#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
	x = 0;
	y = 0;
}
Vector2Int::Vector2Int(POINT point)
{
	x = static_cast<int>(point.x);
	y = static_cast<int>(point.y);
}

Vector2Int::Vector2Int(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2Int Vector2Int::operator+(const Vector2Int& other)
{
	return Vector2Int(x + other.x, y + other.y);
}

void Vector2Int::operator+=(const Vector2Int& other)
{
	this->x += other.x;
	this->y += other.y;
}

Vector2Int Vector2Int::operator-(const Vector2Int& other)
{
	return Vector2Int(x - other.x, y - other.y);
}

void Vector2Int::operator-=(const Vector2Int& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

Vector2Int Vector2Int::operator*(const int32 other)
{
	return Vector2Int(x * other, y * other);
}

void Vector2Int::operator*=(const int32 other)
{
	this->x *= other;
	this->y *= other;
}


Vector2Int Vector2Int::operator*(const float other)
{
	return Vector2Int(
		static_cast<int>(x * other), 
		static_cast<int>(y * other));
}
void Vector2Int::operator*=(const float other)
{
	this->x = static_cast<int>(this->x * other);
	this->y = static_cast<int>(this->y * other);
}

int32 Vector2Int::LengthSqrt()
{
	return x * x + y * y;
}

float Vector2Int::Length()
{
	return sqrtf(this->LengthSqrt());
}

int32 Vector2Int::Dot(Vector2Int other)
{
	return x * other.x + y * other.y;
}

bool Vector2Int::operator==(const Vector2Int& other) const
{
	return x == other.x && y == other.y;
}
bool Vector2Int::operator!=(const Vector2Int& other) const
{
	return x != other.x || y != other.y;
}