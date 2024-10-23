#include "pch.h"
#include "Day24Scene.h"
#include "Flipbook.h"
#include "Texture.h"
#include "GameObject.h"
#include "FlipbookRenderer.h"
#include "Day24Player.h"

void Day24Scene::Init()
{
	Super::Init();
	Texture* textureRight = Resource->LoadTexture(L"T_characterRight", L"Day24/PlayerRight.bmp");
	Texture* textureLeft = Resource->LoadTexture(L"T_characterLeft", L"Day24/PlayerLeft.bmp");
	Texture* textureUp = Resource->LoadTexture(L"T_characterUp", L"Day24/PlayerUp.bmp");
	Texture* textureDown = Resource->LoadTexture(L"T_characterDown", L"Day24/PlayerDown.bmp");
	
#pragma region FlipBookInfos
	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 1.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 9;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(200, 200);
		flipbookInfo.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_right_move", flipbookInfo);
	}
	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 1.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 9;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(200, 200);
		flipbookInfo.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_left_move", flipbookInfo);
	}
	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 1.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 9;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(200, 200);
		flipbookInfo.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_up_move", flipbookInfo);
	}
	{
		FlipbookInfo flipbookInfo;
		flipbookInfo.Duration = 1.0f;
		flipbookInfo.Start = 0;
		flipbookInfo.End = 9;
		flipbookInfo.Line = 1;
		flipbookInfo.Loop = true;
		flipbookInfo.Size = Vector2Int(200, 200);
		flipbookInfo.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_down_move", flipbookInfo);
	}
#pragma endregion

	{
		player = new Day24Player();
		player->Init();
		this->SpawnGameObject(player);
	}
}
void Day24Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day24Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

}
void Day24Scene::Update()
{
	Super::Update();
	if (Input->GetKeyDown(KeyCode::W))
	{
		player->SetDir(Vector2::Up());
		player->SetState(Day24PlayerState::Move);
	}
	else if (Input->GetKeyDown(KeyCode::S))
	{
		player->SetDir(Vector2::Down());
		player->SetState(Day24PlayerState::Move);
	}

	else if (Input->GetKeyDown(KeyCode::A))
	{
		player->SetDir(Vector2::Left());
		player->SetState(Day24PlayerState::Move);
	}
	else if (Input->GetKeyDown(KeyCode::D))
	{
		player->SetDir(Vector2::Right());
		player->SetState(Day24PlayerState::Move);
	}
	else
	{
		player->SetDir(Vector2::Zero());
		player->SetState(Day24PlayerState::Idle);
	}

	//if (Input->GetKeyDown(KeyCode::S))
	//{
	//	info.FlipbookKey = L"FB_character_down_move";
	//	player->GetComponent<FlipbookRenderer>()->SetInfo(info);
	//}
	//if (Input->GetKey(KeyCode::S))
	//{
	//	Vector2 pos = player->GetPos() + Vector2::Down() * speed * Time->GetDeltaTime();
	//	player->SetPos(pos);
	//	
	//}

	/*
	Unity 방식으로는
	CreatureComponent 만들고
	Dir / State를 만들어주세요.

	이 프레임워크에서는
	Day24Creature
	Dir / State를 만들어주세요.
	*/
	
}
void Day24Scene::Release()
{
	Super::Release();
}

void Day24Scene::MakeFlipbook(vector<Texture> textures)
{

}