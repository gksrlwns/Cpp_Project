#include "pch.h"
#include "Day24Enemy.h"

void Day24Enemy::Init()
{
	Super::Init();
}
void Day24Enemy::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day24Enemy::Update()
{
	Super::Update();
	switch (_state)
	{
	case EDay24EnemyState::Idle:
		Update_Idle();
		break;
	case EDay24EnemyState::Dead:
		Update_Dead();
		break;
	}
}
void Day24Enemy::Release()
{
	Super::Release();
}
void Day24Enemy::Update_Idle()
{

}
void Day24Enemy::Update_Dead()
{

}
void Day24Enemy::SetState(EDay24EnemyState state)
{
	if (_state == state)
		return;

	_state = state;
}