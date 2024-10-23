#pragma once
#include "Scene.h"

class Texture;
class Sprite;
class Stone;
class Day19Scene : public Scene
{
	DECLARE_CHILD(Day19Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

private:

	Texture* _backGroundTexture = nullptr;
	Sprite* _backGround = nullptr;

	Stone* _board[15][15];
};

