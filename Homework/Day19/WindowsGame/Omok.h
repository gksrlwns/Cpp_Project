#pragma once
#include "Scene.h"
class Stone;
class Texture;
class Sprite;
class Omok : public Scene
{
	DECLARE_CHILD(Omok, Scene);
public :
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
private:
	Texture* _backGroundTexture = nullptr;
	Sprite* _backGround = nullptr;

	Stone* _board[15][15];
	Vector2Int _boardStartPos = { 24,20 };
	Vector2Int cellSize = { 40,40 };
};

