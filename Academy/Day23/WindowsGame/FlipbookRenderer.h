#pragma once
#include "Component.h"
#include "Flipbook.h"
struct FlipbookRendererInfo
{
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
	void SetInfo(FlipbookRendererInfo info) { _info = info; }
	FlipbookRendererInfo GetInfo() { return _info; }

	void SetFlipbookInfo(FlipbookInfo info) { _flipbookInfo = info; }
	FlipbookInfo GetFlipbookInfo() { return _flipbookInfo; }


protected:
	FlipbookRendererInfo _info;
	FlipbookInfo _flipbookInfo;
};

