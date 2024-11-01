#pragma once
#include "Component.h"

struct BoxRendererInfo
{
	int Brush;
};

class BoxRenderer : public Component
{
	DECLARE_CHILD(BoxRenderer, Component);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(BoxRendererInfo info) { _info = info; }
	BoxRendererInfo GetInfo() { return _info; }

private:
	BoxRendererInfo _info;
};

