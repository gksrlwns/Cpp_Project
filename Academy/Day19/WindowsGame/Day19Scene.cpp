#include "pch.h"
#include "Day19Scene.h"
#include "Texture.h"
#include "Sprite.h"
void Day19Scene::Init()
{
	_texture = new Texture();
	_texture = _texture->LoadBmp(L"../Resources/Day19/Day19Texture.bmp");

	_sprite = new Sprite(_texture, 0, 0, _texture->GetSize().x / 2, _texture->GetSize().y);
}
void Day19Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day19Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	_texture->Render(hdc, 100, 100);

	_sprite->Render(hdc, 100, 500);
}
void Day19Scene::Update()
{

}
void Day19Scene::Release()
{

}