#pragma once
#include "Scene.h"
class DevScene : public Scene
{
	DECLARE_CHILD(DevScene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


};

