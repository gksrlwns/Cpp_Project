#pragma once
#include "Scene.h"
class GameObject;
class FlipbookRenderer;
class FlipbookRendererInfo;
class Day24Player;
class Day24Scene : public Scene
{
	DECLARE_CHILD(Day24Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
	void MakeFlipbook(vector<Texture> textures);
public :
	Day24Player* player;
	FlipbookRenderer* flipbookRender;
	float speed = 10;
};

