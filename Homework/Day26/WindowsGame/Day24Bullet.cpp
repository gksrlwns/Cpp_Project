#include "pch.h"
#include "Day24Bullet.h"
#include "BoxRenderer.h"
#include "Scene.h"
#include "BoxCollider.h"
void Day24Bullet::Init()
{
	Super::Init();

	this->SetBody(CenterRect(0,0,30,30));
	{
		BoxRenderer* component = new BoxRenderer();
		component->SetInfo({ DKGRAY_BRUSH });
		this->AddComponent(component);
	}


	{
		BoxCollider* component = new BoxCollider();
		CenterRect info = CenterRect(0, 0, 30, 30);
		component->SetCollision(info);
		this->AddComponent(component);
	}

	_moveDistance = 0;

}
void Day24Bullet::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day24Bullet::Update()
{
	Super::Update();

	switch (_state)
	{
	case EDay24BulletState::Move:
		this->Update_Move();
		break;
	case EDay24BulletState::Fire:
		this->Update_Fire();
		break;
	}
}
void Day24Bullet::Release()
{
	Super::Release();
}

void Day24Bullet::Update_Move()
{
	this->_body.pos += _info.Dir * Time->GetDeltaTime() * _info.Speed;

	//총알이 움직인 거리가 1000 px 되면 씬에서 삭제
	_moveDistance += Time->GetDeltaTime() * _info.Speed;
	if (1000 < _moveDistance)
	{
		CurrentScene->DespawnGameObject(this);
	}
}

void Day24Bullet::Update_Fire()
{

}

void Day24Bullet::SetState(EDay24BulletState state)
{
	if (_state == state)
		return;

	_state = state;
}