#pragma once
#include "Scene.h"
class Day22Scene : public Scene
{
	DECLARE_CHILD(Day22Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

