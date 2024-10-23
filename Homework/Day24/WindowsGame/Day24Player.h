#pragma once
#include "GameObject.h"

enum class Day24PlayerState
{
	None,
	Idle,
	Move
};
class FlipbookRenderer;
class Day24Player : public GameObject
{
    DECLARE_CHILD(Day24Player, GameObject);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
	void Move();

	void SetState(Day24PlayerState state) { _state = state; }
	void SetDir(Vector2 dir);
private:
	float speed = 100;
	Vector2 _dir = {};
	Day24PlayerState _state = Day24PlayerState::None;
	FlipbookRenderer* _flipbookRenderer;
};

