#pragma once
#include "Component.h"
#include "Flipbook.h"
struct FlipbookRendererInfo
{
	wstring FlipbookKey;
	int Index = 0;
	float SumTime = 0.0f;
};

class FlipbookRenderer : public Component
{
	DECLARE_CHILD(FlipbookRenderer, Component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(FlipbookRendererInfo info);
	FlipbookRendererInfo GetInfo() { return _info; }

protected:
	FlipbookRendererInfo _info;
	Flipbook* _flipbook = nullptr;
};

