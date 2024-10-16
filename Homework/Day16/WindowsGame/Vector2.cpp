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