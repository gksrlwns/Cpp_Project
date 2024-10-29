#pragma once
#include "GameObject.h"

enum class Day21BallState
{
	None,
	Ready,
	Play,
};

class Day21Paddle;
class Day21Ball : public GameObject
{
	DECLARE_CHILD(Day21Ball, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
	virtual string ToString();

public:
	void Update_Ready();
	void Update_Play();

public:
	void Move(Vector2 dir);

public:
	virtual void OnTriggerEnter(Collider* collider, Collider* other);
	virtual void OnTriggerExit(Collider* collider, Collider* other);

public:
	void SetState(Day21BallState state) { _state = state; }
	Day21BallState GetState() { return _state; }

private:
	float _speed = 800.0f;
	Day21BallState _state = Day21BallState::None;
	Vector2 _dir = {};
	Day21Paddle* _paddle = nullptr;
};

// 볼의 기능
//  상태에 따라달라짐

// 1. 볼 Ready 상태에서는 패들위에 고정
// 2. 볼 Play 상태에서는 이동방향대로 움직임
// 3. 벽면 양쪽이랑 위쪽에 부딪히면 꺽임
// 4. 벽돌이랑 부딪히면 꺽임