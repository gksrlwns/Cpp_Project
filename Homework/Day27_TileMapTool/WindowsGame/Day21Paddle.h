#pragma once
#include "GameObject.h"
class Day21Paddle : public GameObject
{
	DECLARE_CHILD(Day21Paddle, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Move(Vector2 dir);

private:
	float _speed = 300.0f;
};


// 패널의 기능은 무엇이 있을까
// 1. A키와 D키를 누르면 body가 움직인다.
// 2. 네모낳게 혹은 스프라이트로 보여야한다.
// 3. 공이랑 충돌시 어떻게한다.