#pragma once
struct Vector2Int
{
	int x = 0;
	int y = 0;

	Vector2Int();
	Vector2Int(POINT point);
	Vector2Int(int x, int y);

	Vector2Int operator+(const Vector2Int& other);
	void operator+=(const Vector2Int& other);

	Vector2Int operator-(const Vector2Int& other);
	void operator-=(const Vector2Int& other);
	
	Vector2Int operator*(const int32 other);
	void operator*=(const int32 other);

	Vector2Int operator*(const float other);
	void operator*=(const float other);

	int32 LengthSqrt();
	float Length();
	int32 Dot(Vector2Int other);

	bool operator==(const Vector2Int& other) const;
	bool operator!=(const Vector2Int& other) const;



};