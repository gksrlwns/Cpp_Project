#pragma once
#include "GameObject.h"
enum class EDay24BulletState
{
	None,
	Move,
	Fire
};
struct Day24BulletInfo
{
	Vector2 Dir = {};
	float Speed = 0;
};
class Day24Bullet : public GameObject
{
	DECLARE_CHILD(Day24Bullet, GameObject);
	
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Update_Move();
	void Update_Fire();

public:
	void SetState(EDay24BulletState state);
	void SetInfo(Day24BulletInfo info) { _info = info; }
private:
	EDay24BulletState _state = EDay24BulletState::None;
	Day24BulletInfo _info;

	float _moveDistance = 0;
};

