#pragma once
#include "Component.h"

//Scene의 카메라를 이동시키는 역할
class CameraComponent : public Component
{
	DECLARE_CHILD(CameraComponent, Component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

