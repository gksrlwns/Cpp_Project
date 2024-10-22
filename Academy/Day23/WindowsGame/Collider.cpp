#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Collider::Update()
{
	Super::Update();
}
void Collider::Release()
{
	Super::Release();
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}

bool Collider::CheckCollision(Collider* other)
{
	// Layer끼리 충돌할 상황이 맞는지 체크하는게 1번
	// 그다음이 충돌체크가 되는지가 2번

	uint32 myFlag = this->_collisionFlag;
	uint8 otherLayer = other->GetCollisionLayer();	// 3

	// 비트연산자 처음배우는거니까 실습하면서 넘어갈게요

	// 0000 0000 0000 0000 0000 0010 0000 0001 
	//									  1
	// 얘의 결과가 지금 비트플래그가 되었냐?

	// 되었으면 true 리턴
	// 안되었으면 false 리턴

	uint32 checkOtherFlag = 1 << otherLayer;


	if (0 < (myFlag & checkOtherFlag))
	{
		//상대기준에서도 내거를 체크
		uint32 checkMyFlag = 1 << this->GetCollisionLayer();
		if (0 < (other->GetCollisionFlag() & checkMyFlag))
		{
			return true;
		}
	}

	return false;
}

void Collider::AddCollisionFlagLayer(CollisionLayerType layer)
{
	//this->_collisionFlag; 이변수가
	// 0000 0000 0000 0000 0000 0010 0000 0001 
	// 여기에서 2가 들어오면
	// 0000 0000 0000 0000 0000 0000 0000 0100

	// 결과값이
	// 0000 0000 0000 0000 0000 0010 0000 0101 

	//_collisionFlag = _collisionFlag | (1 << layer);
	_collisionFlag |= (1 << layer);

}
void Collider::RemoveCollisionFlagLayer(CollisionLayerType layer)
{
	// 0000 0000 0000 0000 0000 0010 0000 0001 
	// 0이들어오면
	// 0000 0000 0000 0000 0000 0000 0000 0001

	// 결과값이
	// 0000 0000 0000 0000 0000 0010 0000 0000


	// 0000 0000 0000 0000 0000 0000 0000 0001
	// 이거를 not연산
	// 1111 1111 1111 1111 1111 1111 1111 1110
	// 0000 0000 0000 0000 0000 0010 0000 0001 
	// and

	//_collisionFlag = _collisionFlag & (~(1 << layer));
	_collisionFlag &= ~(1 << layer);
}
void Collider::ResetCollisionFlagLayer()
{
	_collisionFlag = 0;
}