#pragma once
#include "Scene.h"

class Texture;
class Sprite;
class Day19Scene : public Scene
{
	DECLARE_CHILD(Day19Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

private:
	Texture* _texture = nullptr;
	Sprite* _sprite = nullptr;
};

