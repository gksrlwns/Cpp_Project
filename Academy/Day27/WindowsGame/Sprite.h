#pragma once
#include "ResourceBase.h"

class Texture;
class Sprite : public ResourceBase
{
	DECLARE_CHILD(Sprite, ResourceBase);
public:
	Sprite(Texture* texture, int x, int y, int cx, int cy);

public:
	HDC GetDC();
	int32 GetTransparent();
	Vector2Int GetPos();
	Vector2Int GetSize();
	void Render(HDC hdc, int x, int y);

protected:
	Texture* _texture = nullptr;
	int _x, _y;
	int _cx, _cy;
};

