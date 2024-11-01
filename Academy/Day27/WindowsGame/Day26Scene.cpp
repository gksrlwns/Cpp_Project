#include "pch.h"
#include "Day26Scene.h"
#include "Tilemap.h"
#include "Sprite.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
void Day26Scene::Init()
{
	Super::Init();

	{
		vector<Sprite*> sprites;

		sprites.push_back(nullptr);
		for (int i = 1; i <= 17; i++)
		{
			wstring tileTextureFileName = format(L"Day26/tile_{:02d}.bmp", i);
			wstring tileTextureKeyName = format(L"T_Tile_{:02d}", i);
			wstring tileSpriteKeyName = format(L"S_Tile_{:02d}", i);

			Texture * texture = Resource->LoadTexture(tileTextureKeyName, tileTextureFileName);
			Sprite* sprite = Resource->CreateSprite(tileSpriteKeyName, texture);

			sprites.push_back(sprite);
		}

		//Tilemap 로드
		Tilemap* tilemap = Resource->LoadTilemap(L"TM_Test", L"Day26/map.txt", sprites);
	}


	{
		GameObject* gameObject = new GameObject();
		gameObject->SetPos({ 0, 0 });
		
		{
			TilemapRenderer* component = new TilemapRenderer();
			TilemapRendererInfo info;
			info.Tilemap = Resource->GetTilemap(L"TM_Test");
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}

		this->SpawnGameObject(gameObject);
	}


}
void Day26Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day26Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	{
		wstring mouseStr = ::format(L"X[{}] Y[{}]", Input->GetMousePos().x, Input->GetMousePos().y);
		Draw::Text(hdc, 0, 40, mouseStr);
	}

}
void Day26Scene::Update()
{
	Super::Update();
}
void Day26Scene::Release()
{
	Super::Release();
}