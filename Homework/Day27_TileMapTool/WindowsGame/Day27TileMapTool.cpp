#include "pch.h"
#include "Day27TileMapTool.h"
#include "GameObject.h"
#include "TilemapRenderer.h"
#include "Tilemap.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"
void Day27TileMapTool::Init()
{
	Super::Init();
	//  1. 타일스프라이트 선택할수있게 툴바 제공
	//	2. 맵에 색칠하는느낌으로 Input->GetKey 로 해당 위치의 타일을 현재 선택한 스프라이트로 변경가능하게
	//	3. 맵사이즈는 자동계산
	//	4. 툴바에 카메라 모드 선택해서 카메라 모드일시, wasd로 카메라 이동시킬 수 있도록

	//	(툴바는 어떻게 만드나요 ? )
	//	- UI를 안배워서 못만들것처럼 보이는건데
	//	- 카메라위치에 따라서 변하지않는 GameObject를 만들어주시면 됩니다.
	//	(Renderer에 다 옵션주면 돼요) (bool _ignoreCameraPos)

	/* 타일스프라이트의 종류만큼 하단에 정렬한다.
	*  선택한 타일스프라이트를 보드를 누르면 스프라이트의 크기만큼 생성된다.
	*
	* 지우기 버튼을 누르고 보드를 누르면 타일스프라이트가 지워진다.
	*
	* 저장하기 버튼 클릭 시 tileMap이 저장된다.
	*
	* 불러오기 버튼 클릭 시 tileMap이 불러와진다.
	*/
	//
	// ====================================================
	// 현재 BOXcollider를 통해 구분짓는것 까지 함
	// 1. _tilemapDrawGameObject를 통해 tilemap을 만들고
	// 선택한 영역에 tile이 만들어지고 tilemap에 추가되도록 만들기
	// 1-1) _tilemapDrawGameObject에도 boxCollider 만들기
	// 1-2) 
	// 2. 만들어진 tilemap Save
	// 
	// ====================================================
	//
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
		//Tilemap* tilemap = Resource->LoadTilemap(L"TM_Test", L"Day26/map.txt", sprites);
		_tilemapList = new Tilemap();
		_tilemapList->SetMapSize({ 10,2 });
		_tilemapList->SetSprites(sprites);
		auto _tiles = vector<vector<Tile>>(2, vector<Tile>(_tilemapList->GetMapSize().x));
		for (int i = 0; i < _tilemapList->GetMapSize().y; i++)
		{
			for (int j = 0; j < _tilemapList->GetMapSize().x; j++)
			{
				_tiles[i][j].Value = (i* _tilemapList->GetMapSize().x) + j+1;
			}
		}
		_tilemapList->SetTiles(_tiles);

		{
			GameObject* gameObject = new GameObject();
			
			gameObject->SetPos({ 0, WIN_SIZE_Y - (static_cast<float>(_tilemapList->GetTileSize().y)) * 2});
			{
				TilemapRenderer* component = new TilemapRenderer();
				TilemapRendererInfo info;
				info.Tilemap = _tilemapList;
				component->SetInfo(info);
				gameObject->AddComponent(component);
				_tilemapListRenderer = component;
			}
			{
				BoxCollider* component = new BoxCollider();
				component->SetCollision(CenterRect::MakeLTWH(0,
					0,
					WIN_SIZE_X,
					static_cast<float>(_tilemapList->GetTileSize().y) * 2));
				gameObject->AddComponent(component);
				_tilemapListBoxCollider = component;
			}
	
			this->SpawnGameObject(gameObject);
			_tilemapListGameObject = gameObject;
		}
	}
}
void Day27TileMapTool::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day27TileMapTool");
		Draw::Text(hdc, 0, 20, nameStr);
		//Draw::Rectangle(hdc, _tilemapListGameObject->GetBody().ToRect());
	}
}
void Day27TileMapTool::Update()
{
	Super::Update();
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		if (!Collision::PtInRect(Input->GetMousePos(), _tilemapListBoxCollider->GetCollision().ToRect()))
		{
			return;
		}
		Tilemap* tilemap = _tilemapListRenderer->GetInfo().Tilemap;
		if (tilemap == nullptr)
		{
			return;
		}
		//_tilemap->GetPos() + 인덱스 * _tilemap->GetTileSize()
		//Input->GetMousePosVector2().x 이 좌표가 타일맵의 어떤 인덱스인지 구하는 공식
		Vector2 temp = Input->GetMousePosVector2() - _tilemapListGameObject->GetPos();
		int x = static_cast<int>(temp.x / tilemap->GetTileSize().x);
		int y = static_cast<int>(temp.y / tilemap->GetTileSize().y);
		Tile tile = tilemap->GetTileAt({ x, y });
		if (tile.Value > 17)
		{
			_choiceTileValue = 0;
		}
		_choiceTileValue = tile.Value;
		printf("ChoiceValue : {%d}", _choiceTileValue);
	}

	/*
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
	*/
}
void Day27TileMapTool::Release()
{
	Super::Release();
}