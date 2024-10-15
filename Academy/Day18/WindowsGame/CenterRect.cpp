#include "pch.h"
#include "CenterRect.h"

void CenterRect::Draw(HDC hdc)
{
	int x = static_cast<int>(this->pos.x);
	int y = static_cast<int>(this->pos.y);
	int width = static_cast<int>(this->width);
	int height = static_cast<int>(this->height);

	Draw::Rectangle(hdc, x, y, width,height);
}

CenterRect::CenterRect(float x, float y, float width, float height)
{
	this->pos = Vector2(x, y);
	this->width = width;
	this->height = height;
}
CenterRect::CenterRect(float x, float y)
{
	this->pos = Vector2(x, y);
	this->width = 0;
	this->height = 0;
}
CenterRect::CenterRect()
{
	this->pos = Vector2(0, 0);
	this->width = 0;
	this->height = 0;
}

RECT CenterRect::ToRect()
{
	//left 좌표는 중심좌표 - 전체가로길이 / 2
	LONG left = static_cast<LONG>(pos.x - width / 2);
	LONG top = static_cast<LONG>(pos.y - height / 2);
	LONG right = static_cast<LONG>(pos.x + width / 2);
	LONG bottom = static_cast<LONG>(pos.y + height / 2);

	RECT rc = { left, top, right, bottom };
	return rc;
}

CenterRect CenterRect::FromRect(RECT rc)
{
	float width = static_cast<float>(rc.right - rc.left);
	float height = static_cast<float>(rc.bottom - rc.top);
	float x = static_cast<float>(rc.left + width / 2);
	float y = static_cast<float>(rc.top + height / 2);

	return CenterRect(x, y, width, height);
}