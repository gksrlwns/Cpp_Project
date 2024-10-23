#include "pch.h"
#include "Omok.h"
#include "Texture.h"
#include "Sprite.h"
#include "Stone.h"

void Omok::Init()
{
	Texture* backGroundTexture = Resource->LoadTexture(L"T_Background", L"Day19/omok.bmp");
	/*_backGroundTexture = new Texture();
	_backGroundTexture = _backGroundTexture->LoadBmp(L"../Resources/Day19/omok.bmp");*/

	_backGround = Resource->CreateSprite(L"S_Background", backGroundTexture);
	/*_backGround = new Sprite(_backGroundTexture, 0, 0, _backGroundTexture->GetSize().x, _backGroundTexture->GetSize().y);*/
	Texture* blackStroneTexture = Resource->LoadTexture(L"T_BlackStone", L"Day19/bRock.bmp");
	Resource->CreateSprite(L"S_BlackStone", blackStroneTexture);
	Texture* whiteStroneTexture = Resource->LoadTexture(L"T_WhiteStone", L"Day19/wRock.bmp");
	Resource->CreateSprite(L"S_WhiteStone", blackStroneTexture);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			_board[i][j] = nullptr;
		}
	}
}
void Omok::Render(HDC hdc)
{
	_backGround->Render(hdc, 0, 0);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (_board[i][j] == nullptr)
			{
				continue;
			}
			_board[i][j]->Render(hdc);
		}
	}
}
void Omok::Update()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Vector2Int mousePos = Input->GetMousePos();
		int x = mousePos.x / _boardStartPos.x;
		int y = mousePos.y / _boardStartPos.y;
		
		int cellX = x / cellSize.x;
		int cellY = y / cellSize.y;

		_board[cellY][cellX] = new Stone();
		_board[cellY][cellX]->Init();
		_board[cellY][cellX]->SetInfo(Vector2Int(cellX,cellY),StoneType::Black);
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (_board[i][j] == nullptr)
			{
				continue;
			}
			_board[i][j]->Update();
		}
	}
}
void Omok::Release()
{

}