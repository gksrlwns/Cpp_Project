#pragma once
#include "Component.h"

class Tilemap;
struct TilemapRendererInfo
{
	Tilemap* Tilemap;
};

class TilemapRenderer : public Component
{
	DECLARE_CHILD(TilemapRenderer, Component)

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetInfo(TilemapRendererInfo info) { _info = info; }
	TilemapRendererInfo GetInfo() { return _info; }

protected:
	TilemapRendererInfo _info;
};

