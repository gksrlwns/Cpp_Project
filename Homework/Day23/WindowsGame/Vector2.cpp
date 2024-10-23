#include "pch.h"
#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(POINT pt)
{
	this->x = static_cast<float>(pt.x);
	this->y = static_cast<float>(pt.y);
}

Vector2 Vector2::operator-(const POINT pt)
{
	return Vector2{ static_cast<float>(this->x - pt.x), static_cast<float>(this->y - pt.y) };
}
Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ static_cast<float>(this->x - other.x), static_cast<float>(this->y - other.y) };
}
void Vector2::operator-=(const Vector2 other)
{
	this->x -= other.x;
	this->y -= other.y;
}
void Vector2::operator-=(const POINT pt)
{
	this->x -= static_cast<float>(pt.x);
	this->y -= static_cast<float>(pt.y);
}
Vector2 Vector2::operator+(const POINT pt)
{
	return Vector2{ static_cast<float>(this->x + pt.x), static_cast<float>(this->y + pt.y) };
}
Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ static_cast<float>(this->x + other.x), static_cast<float>(this->y + other.y) };
}
void Vector2::operator+=(const Vector2 other)
{
	this->x += other.x;
	this->y += other.y;
}
void Vector2::operator+=(const POINT pt)
{
	this->x += static_cast<float>(pt.x);
	this->y += static_cast<float>(pt.y);
}
Vector2 Vector2::operator*(const float other)
{
	return Vector2{ static_cast<float>(this->x * other), static_cast<float>(this->y * other) };
}
void Vector2::operator*=(const float other)
{
	this->x *= other;
	this->y *= other;
}
Vector2 Vector2::operator/(const float other)
{
	return Vector2{ static_cast<float>(this->x / other), static_cast<float>(this->y / other) };
}
void Vector2::operator/=(const float other)
{
	this->x /= other;
	this->y /= other;
}
bool Vector2::operator==(const Vector2 other)
{
	if (EQUALS(this->x, other.x) && EQUALS(this->y, other.y))
	{
		return true;
	}

	return false;
}
bool Vector2::operator!=(const Vector2 other)
{
	if (EQUALS(this->x, other.x) && EQUALS(this->y, other.y))
	{
		return false;
	}

	return true;
}

float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}
float Vector2::Dot(Vector2 vec1, Vector2 vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

Vector2 Vector2::Reflect(Vector2 normal)
{
	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedoriginVector = this->Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedoriginVector.Dot(normalizedNormalVector * -1);
	temp *= tempLength;

	return normalizedoriginVector + temp * 2;
}
Vector2 Vector2::Reflect(Vector2 origin, Vector2 normal)
{
	Vector2 normalizedNormalVector = normal.Normalize();
	Vector2 normalizedoriginVector = origin.Normalize();

	Vector2 temp = normalizedNormalVector;
	float tempLength = normalizedoriginVector.Dot(normalizedNormalVector * -1);
	temp *= tempLength;

	return normalizedoriginVector + temp * 2;
}

float Vector2::LengthSqrt()
{
	return static_cast<float>(x * x + y * y);
}
float Vector2::Length()
{
	return static_cast<float>(::sqrt(x * x + y * y));
}
Vector2 Vector2::Normalize()
{
	// 현재 벡터를 길이를 1로 만든다.
	float length = this->Length();

	if (length <= 0.0000000000001f)
	{
		return *this;
	}

	return Vector2(x / length, y / length);
}