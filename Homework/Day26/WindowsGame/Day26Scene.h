#pragma once
#include "Scene.h"
class Day26Scene : public Scene
{
	DECLARE_CHILD(Day26Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;



};

