#include "pch.h"
#include "Day24Enemy.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"
#include "Day24Bullet.h"
#include "Scene.h"

void Day24Enemy::Init()
{
	Super::Init();

	this->SetInfo({ 3 });

	Vector2 pos = this->GetPos();
	this->SetBody(CenterRect(pos.x, pos.y, 80, 80));

	{
		BoxRenderer* component = new BoxRenderer();
		BoxRendererInfo info;
		info.Brush = GRAY_BRUSH;
		component->SetInfo(info);
		this->AddComponent(component);
	}
	{
		BoxCollider* component = new BoxCollider();
		CenterRect info = CenterRect(0, 0, 80, 80);
		component->SetCollision(info);
		this->AddComponent(component);
	}
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

void Day24Enemy::OnTriggerEnter(Collider* collider, Collider* other)
{
	// 1. other가 총알인지 확인
	GameObject* otherOwner = other->GetOwner();

	Day24Bullet* otherBullet = dynamic_cast<Day24Bullet*>(otherOwner);
	if (otherBullet != nullptr)
	{
		// 1. 데미지를 준다.
		this->OnDamaged(otherBullet);
		
		// 2. 총알을 삭제한다.
		CurrentScene->DespawnGameObject(otherBullet);
	}
}

void Day24Enemy::OnDamaged(Day24Bullet* bullet)
{
	// HP를 하나 줄인다.
	_info.Hp--;

	// HP가 0보다 작으면 소멸한다.
	if (_info.Hp <= 0)
	{
		CurrentScene->DespawnGameObject(this);
	}
}