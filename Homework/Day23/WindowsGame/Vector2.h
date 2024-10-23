#pragma once
struct Vector2
{
	float x = 0, y = 0;

	Vector2(float x, float y);
	Vector2();
	Vector2(POINT pt);

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	void operator-=(const Vector2 other);
	void operator-=(const POINT pt);
	Vector2 operator+(const POINT pt);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	void operator+=(const POINT pt);
	Vector2 operator*(const float other);
	void operator*=(const float other);
	Vector2 operator/(const float other);
	void operator/=(const float other);
	bool operator==(const Vector2 other);
	bool operator!=(const Vector2 other);

	inline static Vector2 Zero()
	{
		return Vector2(0, 0);
	}
	inline static Vector2 Up()
	{
		return Vector2(0, -1);
	}
	inline static Vector2 Right()
	{
		return Vector2(1, 0);
	}
	inline static Vector2 Down()
	{
		return Vector2(0, 1);
	}
	inline static Vector2 Left()
	{
		return Vector2(-1, 0);
	}


	float Dot(Vector2 other);
	static float Dot(Vector2 vec1, Vector2 vec2);

	//반사벡터 구하기
	/*
	Original Vector
		  ^
		  |
		  /
		 /
		/      Normal
	   /      /
	  +------->
	  \
	   \
		\
		 \  Reflected Vector
		  \
		   V
	*/
	// 1. 법선벡터와 origin vector를 내적한다
	// 2. 내적을 구한값에 2를 곱한다
	// 3. 2에서 구한값을 원래 벡터에서 뺀다.
	Vector2 Reflect(Vector2 normal);
	static Vector2 Reflect(Vector2 origin, Vector2 normal);

	//magnitude
	float LengthSqrt();
	float Length();
	//길이를 1인 벡터로 만드는거
	// # 방향벡터는 무조건 길이가 1이어야 정상동작을 함.
	Vector2 Normalize();
};

