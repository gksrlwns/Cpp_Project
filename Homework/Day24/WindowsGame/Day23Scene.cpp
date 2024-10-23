#include "pch.h"
#include "Day23Scene.h"
#include "Flipbook.h"
#include "Texture.h"
#include "GameObject.h"
#include "FlipbookRenderer.h"

void Day23Scene::Init()
{
	Texture* texture = Resource->LoadTexture(L"T_character", L"Day23/spritesheet_character.bmp");

	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 1.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 6;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(50, 37);
		flipbookInfo.Texture = texture;
		Resource->CreateFlipbook(L"FB_character_right_move", flipbookInfo);
	}

	{
		GameObject* gameObject = new GameObject();
		gameObject->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		{
			FlipbookRenderer* componenet = new FlipbookRenderer();
			FlipbookRendererInfo info;
			info.FlipbookKey = L"FB_character_right_move";
			componenet->SetInfo(info);
			gameObject->AddComponent(componenet);
		}
		this->SpawnGameObject(gameObject);
	}
}
void Day23Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day23Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

}
void Day23Scene::Update()
{
	Super::Update();
	Resource->GetFlipbook(L"FB_character_right_move")->Update();
}
void Day23Scene::Release()
{
	Super::Release();
}