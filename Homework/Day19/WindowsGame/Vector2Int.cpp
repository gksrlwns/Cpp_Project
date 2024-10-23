#include "pch.h"
#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
	x = 0;
	y = 0;
}
Vector2Int::Vector2Int(Vector2 vector)
{
	x = static_cast<int>(vector.x);
	y = static_cast<int>(vector.y);
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