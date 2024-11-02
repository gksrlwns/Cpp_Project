#include "pch.h"
#include "Day19Stone.h"
#include "Texture.h"
#include "Sprite.h"
void Day19Stone::Init()
{

}
void Day19Stone::Render(HDC hdc)
{
	int renderX = _boardStartPos.x + _pos.x * _cellSize.x;
	int renderY = _boardStartPos.y + _pos.y * _cellSize.y;
	if (_type == 0)
	{
		Resource->GetSprite(L"S_BlackStone")->Render(hdc, renderX, renderY);
	}
	else if (_type == 1)
	{
		Resource->GetSprite(L"S_WhiteStone")->Render(hdc, renderX, renderY);
	}
}
void Day19Stone::Update()
{

}
void Day19Stone::Release()
{
}
void Day19Stone::SetInfo(Vector2Int pos, int type)
{
	_pos = pos;
	_type = type;
}