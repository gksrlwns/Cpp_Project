#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "GameObject.h"

void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	// 실질적인 충돌체크
	/*-A collider와 B collider가 충돌했다.라는걸 알려줌.
		- OnTriggerEnter(충돌이 시작하였을 때)
		- OnTriggerExit(충돌이 끝났을 때)*/

	// 수도코드
	// 1. 모든 Collider를 한번씩 비교한다 [각 비교자 이름(Collider c1, Collider c2)]
	//	 2. c1와 c2가 충돌되었으면
	//		3.충돌 Map에 없으면
	//			4.충돌 Map에 넣어준다.
	//			5.충돌 되었다고 GameObject에 알려준다. (OnTriggerEnter)
	//	 2. c1와 c2가 충돌이 안되었다면
	//		3. 충돌Map안에 있으면
	//			4. 충돌 Map에서 꺼내준다.
	//			5. 충돌이 끝났다고 GameObject에 알려준다. (OnTriggerExit)

	
	for (int i = 0; i < _colliders.size(); i++)
	{
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c1 = _colliders[i];
			Collider* c2 = _colliders[j];

			if (c1->CheckCollision(c2))
			{
				//충돌 Map에 없으면
				if (false == c1->_collisionMap.contains(c2))
				{
					//충돌 Map에 넣어준다.
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
					//충돌 되었다고 GameObject에 알려준다. (OnTriggerEnter)
					c1->GetOwner()->OnTriggerEnter(c1, c2);
					c2->GetOwner()->OnTriggerEnter(c2, c1);
				}
			}
			else
			{
				//충돌Map안에 있으면
				if (true == c1->_collisionMap.contains(c2))
				{
					//충돌 Map에서 꺼내준다.
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
					//충돌이 끝났다고 GameObject에 알려준다. (OnTriggerExit)
					c1->GetOwner()->OnTriggerExit(c1, c2);
					c2->GetOwner()->OnTriggerExit(c2, c1);
				}
			}
		}
	}


}
void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}
void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);

	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}
void CollisionManager::ClearCollider()
{
	_colliders.clear();
}