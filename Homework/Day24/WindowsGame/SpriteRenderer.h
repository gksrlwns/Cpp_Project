#pragma once
#include "Component.h"

struct SpriteRendererInfo
{
	wstring SpriteKey;
	Vector2 Offset;
};

class SpriteRenderer : public Component
{
	DECLARE_CHILD(SpriteRenderer, Component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(SpriteRendererInfo info) { _info = info; }
	SpriteRendererInfo GetInfo() { return _info; }

protected:
	SpriteRendererInfo _info;
};


