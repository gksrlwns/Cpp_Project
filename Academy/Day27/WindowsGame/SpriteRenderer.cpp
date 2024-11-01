#include "pch.h"
#include "SpriteRenderer.h"
#include "Sprite.h"
#include "GameObject.h"
#include "Scene.h"
void SpriteRenderer::Init()
{
	Super::Init();
}
void SpriteRenderer::Render(HDC hdc)
{
	Super::Render(hdc);

	Sprite* sprite = Resource->GetSprite(_info.SpriteKey);

	if (sprite == nullptr) return;

	GameObject* owner = this->GetOwner();

	if (owner == nullptr) return;

	Vector2 pos = owner->GetPos();
	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2Int renderPos = { 
		static_cast<int>(pos.x + _info.Offset.x - cameraPos.x), 
		static_cast<int>(pos.y + _info.Offset.y - cameraPos.y)
	};

	sprite->Render(hdc, renderPos.x, renderPos.y);
}
void SpriteRenderer::Update()
{
	Super::Update();
}
void SpriteRenderer::Release()
{
	Super::Release();
}