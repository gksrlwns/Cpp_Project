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
	void SetIgnoreCamPos(bool ignoreCamPos) { _ignoreCamPos = ignoreCamPos; }
	bool GetIgnoreCmaPos() { return _ignoreCamPos; }

protected:
	TilemapRendererInfo _info;
	bool _ignoreCamPos = false;
};

