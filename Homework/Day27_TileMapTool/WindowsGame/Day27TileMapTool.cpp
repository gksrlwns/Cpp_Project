#include "pch.h"
#include "Day27TileMapTool.h"
#include "GameObject.h"
#include "TilemapRenderer.h"
#include "Tilemap.h"
#include "BoxRenderer.h"
#include "BoxCollider.h"
#include "TextBox.h"
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

		for (int i = 0; i <= 17; i++)
		{
			wstring tileTextureFileName = format(L"Day26/tile_{:02d}.bmp", i);
			wstring tileTextureKeyName = format(L"T_Tile_{:02d}", i);
			wstring tileSpriteKeyName = format(L"S_Tile_{:02d}", i);

			Texture* texture = Resource->LoadTexture(tileTextureKeyName, tileTextureFileName);
			Sprite* sprite = Resource->CreateSprite(tileSpriteKeyName, texture);

			sprites.push_back(sprite);
		}
#pragma region MakeTileListMap

		_tilemapList = new Tilemap();
		_tilemapList->SetMapSize({ 10,2 });
		_tilemapList->SetSprites(sprites);
		{
			int x = _tilemapList->GetMapSize().x;
			int y = _tilemapList->GetMapSize().y;
			auto _tiles = vector<vector<Tile>>(y, vector<Tile>(x));
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					_tiles[i][j].Value = (i * x) + j + 1;
				}
			}
			_tilemapList->SetTiles(_tiles);
		}

		
#pragma endregion
		
#pragma region MakeDrawTilemap
		_tilemapDraw = new Tilemap();
		_tilemapDraw->SetMapSize({ WIN_SIZE_X / _tilemapList->GetTileSize().x +1,
			(WIN_SIZE_Y - (static_cast<int>(_tilemapList->GetTileSize().y)) * 2) / _tilemapList->GetTileSize().y + 1 });
		{
			int x = _tilemapDraw->GetMapSize().x;
			int y = _tilemapDraw->GetMapSize().y;
			auto _tiles = vector<vector<Tile>>(y, vector<Tile>(x));
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					_tiles[i][j].Value = 0;
				}
			}
			_tilemapDraw->SetTiles(_tiles);
		}
		
		_tilemapDraw->SetSprites(sprites);
		{
			GameObject* gameObject = new GameObject();

			gameObject->SetPos({ 0, 1 });
			{
				TilemapRenderer* component = new TilemapRenderer();
				TilemapRendererInfo info;
				info.Tilemap = _tilemapDraw;
				component->SetInfo(info);
				gameObject->AddComponent(component);
				_tilemapDrawRenderer = component;
			}
			{
				BoxCollider* component = new BoxCollider();
				component->SetCollision(CenterRect::MakeLTWH(0,
					0,
					WIN_SIZE_X,
					WIN_SIZE_Y - static_cast<float>(_tilemapList->GetTileSize().y) * 2));
				gameObject->AddComponent(component);
				_tilemapDrawBoxCollider = component;
			}

			this->SpawnGameObject(gameObject);
			_tilemapDrawGameObject = gameObject;
		}
#pragma endregion
		{
			GameObject* gameObject = new GameObject();

			gameObject->SetPos({ 0, WIN_SIZE_Y - (static_cast<float>(_tilemapList->GetTileSize().y)) * 2 });
			{
				TilemapRenderer* component = new TilemapRenderer();
				TilemapRendererInfo info;
				info.Tilemap = _tilemapList;
				component->SetInfo(info);
				component->SetIgnoreCamPos(true);
				gameObject->AddComponent(component);
				_tilemapListRenderer = component;
			}
			{
				BoxCollider* component = new BoxCollider();
				component->SetCollision(CenterRect::MakeLTWH(0,
					0,
					WIN_SIZE_X - 50,
					static_cast<float>(_tilemapList->GetTileSize().y) * 2));
				gameObject->AddComponent(component);
				_tilemapListBoxCollider = component;
			}

			this->SpawnGameObject(gameObject);
			_tilemapListGameObject = gameObject;
		}
		
//#pragma region Save&Load
//		{
//			GameObject* gameObject = new GameObject();
//
//			gameObject->SetBody(CenterRect::MakeLTWH(WIN_SIZE_X - 50, WIN_SIZE_X - 100, 50, 50));
//			gameObject->SetPos({ WIN_SIZE_X - 50, WIN_SIZE_X - 100 });
//			{
//				BoxCollider* component = new BoxCollider();
//				component->SetCollision(CenterRect::MakeLTWH(WIN_SIZE_X - 50, WIN_SIZE_X - 100, 50, 50));
//				gameObject->AddComponent(component);
//				saveBoxCollider = component;
//			}
//			{
//				TextBox* component = new TextBox();
//				BoxRendererInfo info;
//				info.Brush = { GRAY_BRUSH };
//				component->SetInfo(info);
//				component->SetText(L"Save");
//				component->SetIgnoreCamPos(true);
//				gameObject->AddComponent(component);
//			}
//
//			this->SpawnGameObject(gameObject);
//		}
//#pragma endregion

		this->SetCameraArea(CenterRect::MakeLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
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
	if (Input->GetKey(KeyCode::LeftMouse))
	{
		//printf("GetMousePosVector2{%f,%f}\n", Input->GetMousePosVector2().x, Input->GetMousePosVector2().y);
		if (Collision::PtInRect((Input->GetMousePos()), _tilemapListBoxCollider->GetCollision().ToRect()))
		{
			Vector2 temp = Input->GetMousePosVector2() - _tilemapListGameObject->GetPos();
			int x = static_cast<int>(temp.x / _tilemapList->GetTileSize().x);
			int y = static_cast<int>(temp.y / _tilemapList->GetTileSize().y);
			if (x >= _tilemapList->GetMapSize().x || y >= _tilemapList->GetMapSize().y)
			{
				_choiceTileValue = 0;
				printf("선택 영역을 넘어섬");
				return;
			}
			Tile tile = _tilemapList->GetTileAt({ x, y });
			_choiceTileValue = tile.Value;
			if (_choiceTileValue > 17)
			{
				_choiceTileValue = 0;
			}
			
			printf("ChoiceValue : {%d}\n", _choiceTileValue);
		}
		else if(Collision::PtInRect(Input->GetMousePos(), _tilemapDrawBoxCollider->GetCollision().ToRect()))
		{
			Vector2 temp = (Input->GetMousePosVector2() + _cameraPosition) - _tilemapDrawGameObject->GetPos();
			/*printf("GetMousePosVector2{%f,%f}\n", Input->GetMousePosVector2().x, Input->GetMousePosVector2().y);
			printf("_tilemapDrawGameObject{%f,%f}\n", _tilemapDrawGameObject->GetPos().x, _tilemapDrawGameObject->GetPos().y);
			printf("Temp{%f,%f}\n", temp.x, temp.y);*/
			int x = static_cast<int>(temp.x / _tilemapList->GetTileSize().x);
			int y = static_cast<int>(temp.y / _tilemapList->GetTileSize().y);
			printf("Draw 영역{%d,%d}\n", x, y);
			Tile tile;
			tile.Value = _choiceTileValue;
			_tilemapDraw->SetTileAt({ x,y }, tile);
		}
		
	}

	if (Input->GetKey(KeyCode::S)) 
	{
		_cameraPosition -= Vector2::Down() * 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::W))
	{
		_cameraPosition -= Vector2::Up() * 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::A))
	{
		_cameraPosition -= Vector2::Left() * 100 * Time->GetDeltaTime();
	}
	if (Input->GetKey(KeyCode::D))
	{
		_cameraPosition -= Vector2::Right() * 100 * Time->GetDeltaTime();
	}
	/*if (Input->GetKeyDown(KeyCode::S))
	{
		Tilemap* tilemap = _tilemapDrawRenderer->GetInfo().Tilemap;

		tilemap->SaveFile(L"../Resources/Day26/newMap.txt");
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		Tilemap* tilemap = _tilemapDrawRenderer->GetInfo().Tilemap;

		tilemap->LoadFile(L"../Resources/Day26/newMap.txt");
	}*/
}
void Day27TileMapTool::Release()
{
	Super::Release();
}