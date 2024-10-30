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
class BoxCollider;
class BoxRenderer;
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
	void OnDamaged(float damage);
public:
	void SetState(EDay24EnemyState state);
	void SetInfo(Day24EnemyInfo info) { _info = info; }
	BoxRenderer* GetBoxRenderer() { return _boxRenderer; }
	BoxCollider* GetBoxCollider() { return _boxCollider; }

private:
	EDay24EnemyState _state;
	Day24EnemyInfo _info;
	BoxRenderer* _boxRenderer = nullptr;
	BoxCollider* _boxCollider = nullptr;
	bool isLive = true;

};

