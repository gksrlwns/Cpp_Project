#pragma once
#include "GameObject.h"
class Day21Brick : public GameObject
{
	DECLARE_CHILD(Day21Brick, GameObject);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

