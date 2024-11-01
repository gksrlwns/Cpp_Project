#pragma once
#include "GameObject.h"

enum class EDay24EnemyState
{
	None,
	Idle,
	Dead
};
struct Day24EnemyInfo
{
	float Hp;
};

class Day24Bullet;
class Day24Enemy : public GameObject
{
	DECLARE_CHILD(Day24Enemy, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void Update_Idle();
	void Update_Dead();

public:
	void SetState(EDay24EnemyState state);
	void SetInfo(Day24EnemyInfo info) { _info = info; }

public:
	void OnDamaged(Day24Bullet* bullet);

public:
	virtual void OnTriggerEnter(Collider* collider, Collider* other);

private:
	EDay24EnemyState _state;
	Day24EnemyInfo _info;
};

