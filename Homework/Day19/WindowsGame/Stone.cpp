#include "pch.h"
#include "Stone.h"
#include "Texture.h"
#include "Sprite.h"

void Stone::Init()
{

}
void Stone::Render(HDC hdc)
{
	int renderX = 100;
	int renderY = 100;
	
	switch (_type)
	{
	case StoneType::Black:
		Resource->GetSprite(L"S_BlackStone")->Render(hdc, renderX, renderY);
		break;
	case StoneType::White:
		Resource->GetSprite(L"S_WhiteStone")->Render(hdc, renderX, renderY);
		break;
	}
}
void Stone::Update()
{

}
void Stone::Release()
{
	SAFE_DELETE(_texture);
	SAFE_DELETE(_sprite);
}
void Stone::SetInfo(Vector2Int pos, StoneType type)
{
	this->_pos = pos;
	this->_type = type;
	
	_texture = new Texture();
	_texture->LoadBmp(L"../Resources/Day19/bRock.bmp");


	_sprite = new Sprite(_texture, 0, 0, _texture->GetSize().x / 2, _texture->GetSize().y);
}