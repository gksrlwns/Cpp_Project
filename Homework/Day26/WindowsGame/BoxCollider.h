#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
//	DECLARE_CHILD(BoxCollider, Collider);
	using Super = Collider;
public:
	BoxCollider();
	virtual ~BoxCollider() {}

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	virtual bool CheckCollision(Collider* other);

public:

public:
	void SetCollision(CenterRect collision) { _collision = collision; }
	CenterRect GetCollision();

private:
	CenterRect _collision;
};

