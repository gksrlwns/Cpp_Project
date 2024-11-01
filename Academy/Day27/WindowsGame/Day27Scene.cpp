#include "pch.h"
#include "Day27Scene.h"
#include "Tilemap.h"
#include "Sprite.h"
#include "TilemapRenderer.h"
#include "GameObject.h"
void Day27Scene::Init()
{
	Super::Init();
	// 타일맵 소환


	{
		vector<Sprite*> sprites;

		sprites.push_back(nullptr);
		for (int i = 1; i <= 17; i++)
		{
			wstring tileTextureFileName = format(L"Day26/tile_{:02d}.bmp", i);
			wstring tileTextureKeyName = format(L"T_Tile_{:02d}", i);
			wstring tileSpriteKeyName = format(L"S_Tile_{:02d}", i);

			Texture* texture = Resource->LoadTexture(tileTextureKeyName, tileTextureFileName);
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
			_tilemapRenderer = component;
		}

		this->SpawnGameObject(gameObject);
		_tilemapGameObject = gameObject;
	}


}
void Day27Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day27Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day27Scene::Update()
{
	Super::Update();



	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 1. 해당위치의 타일을 가져온다
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;
		if (tilemap == nullptr)
		{
			return;
		}

		//GetTileAt를 사용하기위해서는 인덱스 계산이 필요합니다.
		// 실제 위치
		//_tilemap->GetPos() + 인덱스 * _tilemap->GetTileSize()
		//Input->GetMousePosVector2().x 이 좌표가 타일맵의 어떤 인덱스인지 구하는 공식
		Vector2 temp = Input->GetMousePosVector2() - _tilemapGameObject->GetPos();
		int x = static_cast<int>(temp.x / tilemap->GetTileSize().x);
		int y = static_cast<int>(temp.y / tilemap->GetTileSize().y);

		//cout << "X : " << x << endl;
		//cout << "Y : " << y << endl;
		Tile tile = tilemap->GetTileAt({ x, y });

		// 2. 해당 타일의 값을 1올린다.
		tile.Value += 1;
		if (tilemap->GetSprites().size() <= tile.Value)
		{
			tile.Value = 1;
		}

		// 3. 해당 타일을 적용한다.
		tilemap->SetTileAt({ x, y }, tile);
	}

	if (Input->GetKeyDown(KeyCode::S))
	{
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;

		tilemap->SaveFile(L"../Resources/Day26/newMap.txt");
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		Tilemap* tilemap = _tilemapRenderer->GetInfo().Tilemap;

		tilemap->LoadFile(L"../Resources/Day26/newMap.txt");
	}
}
void Day27Scene::Release()
{
	Super::Release();
}