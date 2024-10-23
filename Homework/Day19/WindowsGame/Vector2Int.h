#pragma once
struct Vector2Int
{
	int x = 0;
	int y = 0;

	Vector2Int();
	Vector2Int(Vector2 vector);
	Vector2Int(POINT point);
	Vector2Int(int x, int y);
};