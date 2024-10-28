#pragma once
#include "Scene.h"
class Day21Ball;
class Day21Paddle;
class Day21Scene : public Scene
{
	DECLARE_CHILD(Day21Scene, Scene)

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	Day21Ball* GetBall() { return _ball; }
	Day21Paddle* GetPaddle() { return _paddle; }

private:
	Day21Ball* _ball = nullptr;
	Day21Paddle* _paddle = nullptr;
};


