#pragma once
#include "Component.h"
class Collider : public Component
{
	DECLARE_CHILD(Collider, Component);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual bool CheckCollision(Collider* other);

public:
	Collider(ColliderType type) { _colliderType = type; }

public:
	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayerType) { _collisionLayer = collisionLayerType; }

	uint32 GetCollisionFlag() { return _collisionFlag; }
	//이렇게 쓸일이 별로 없음.
	void SetCollisionFlag(uint32 flag) { _collisionFlag = flag; }
	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);
	void ResetCollisionFlagLayer();


	ColliderType GetColliderType() { return _colliderType; }
protected:
	ColliderType _colliderType = ColliderType::None;
	// 내 CollisionLayer는 무엇인지
	CollisionLayerType _collisionLayer = CLT_DEFAULT;

	// 내가 충돌할 CollisionLayerType은 무엇인지
	uint32 _collisionFlag = ~0; // 모든 레이어와 충돌할것이다.
	// (0xFFFFFFFF)
	// 0XF
	//16진법 0123456789ABCDEF

public:
	// 현재 충돌중인 Collider 모음집
	unordered_set<Collider*> _collisionMap;
	//unordered_set => Map이라고 생각하시면됩니다.
	//					찾는게 빨라요.
	//					넣는것도 좀 빨라요.
	//					메모리가 살짝 많이들어요.

};

