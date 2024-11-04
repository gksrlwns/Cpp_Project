#pragma once
#include "Scene.h"
class TilemapRenderer;
class Tilemap;
class BoxCollider;
class Day27TileMapTool : public Scene
{
	DECLARE_CHILD(Day27TileMapTool, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	GameObject* _tilemapListGameObject = nullptr;
	TilemapRenderer* _tilemapListRenderer = nullptr;
	BoxCollider* _tilemapListBoxCollider = nullptr;
	Tilemap* _tilemapList = nullptr;
	int _choiceTileValue = 0;
private:
	GameObject* _tilemapDrawGameObject = nullptr;
	TilemapRenderer* _tilemapDrawRenderer = nullptr;
	BoxCollider* _tilemapDrawBoxCollider = nullptr;
	Tilemap* _tilemapDraw = nullptr;
private:
	GameObject* saveGameObject = nullptr;
	BoxCollider* saveBoxCollider = nullptr;
	
};

