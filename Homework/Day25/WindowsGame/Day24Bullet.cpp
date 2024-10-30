#include "pch.h"
#include "Day24Bullet.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"
#include "Scene.h"
#include "Day24Enemy.h"
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
		component->SetCollision(this->_body);
		component->SetCollisionLayer(CLT_BULLET);
		this->AddComponent(component);
	}

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
void Day24Bullet::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	{
		if (other->GetCollisionLayer() == CLT_ENEMY)
		{
			Day24Enemy* enemy = dynamic_cast<Day24Enemy*>(other->GetOwner());
			if (enemy == nullptr)
			{
				printf("enemy를 찾을 수 없음");
			}
			else
			{
				enemy->OnDamaged(_info.Damage);
				CurrentScene->DespawnGameObject(this);
			}
		}
	}

	
}