#include "pch.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
#include "Scene.h"
#include "Tilemap.h"

void TilemapRenderer::Init()
{
	Super::Init();
}
void TilemapRenderer::Render(HDC hdc)
{
	GameObject* owner = this->GetOwner();
	if (owner == nullptr) return;

	if (_info.Tilemap == nullptr)
	{
		return;
	}

	//Vector2 pos = owner->GetPos();

	Vector2 pos;
	pos.x = owner->GetPos().x + _info.Tilemap->GetTileSize().x / 2;
	pos.y = owner->GetPos().y + _info.Tilemap->GetTileSize().y / 2;

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2Int renderPos = {
		static_cast<int>(pos.x - cameraPos.x),
		static_cast<int>(pos.y - cameraPos.y)
	};

	_info.Tilemap->Render(hdc, renderPos.x, renderPos.y);

	Super::Render(hdc);
}
void TilemapRenderer::Update()
{
	Super::Update();
}
void TilemapRenderer::Release()
{
	Super::Release();
}