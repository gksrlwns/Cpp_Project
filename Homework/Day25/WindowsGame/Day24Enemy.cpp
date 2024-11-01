#include "pch.h"
#include "Day24Enemy.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"

void Day24Enemy::Init()
{
	Super::Init();
	this->SetBody(CenterRect(0, 0, 50, 50));
	{
		BoxRenderer* component = new BoxRenderer();
		component->SetInfo({ BLACK_BRUSH });
		this->AddComponent(component);
		_boxRenderer = component;
	}
	{
		BoxCollider* component = new BoxCollider();
		component->SetCollision(this->_body);
		component->SetCollisionLayer(CLT_ENEMY);
		this->AddComponent(component);
		_boxCollider = component;
	}
	Day24EnemyInfo info;
	info.Hp = 100;
	SetInfo(info);
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
	if (!isLive) return;
	printf("죽음\n");
	_boxRenderer->SetInfo({ GRAY_BRUSH });
	_boxCollider->SetCollisionLayer(CLT_DEAD);
	isLive = false;
}
void Day24Enemy::OnDamaged(float damage)
{
	_info.Hp -= damage;
	printf("enemy에게 %f의 데미지를 입음. 남은 체력 : %f \n", damage, _info.Hp);
	if (_info.Hp <= 0)
	{
		SetState(EDay24EnemyState::Dead);
	}
}
void Day24Enemy::SetState(EDay24EnemyState state)
{
	if (_state == state)
		return;

	_state = state;
}