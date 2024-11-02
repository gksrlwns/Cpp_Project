#include "pch.h"
#include "Day24Scene.h"
#include "Day24Creature.h"
#include "SpriteRenderer.h"
#include "BoxRenderer.h"
#include "CameraComponent.h"
#include "Day24Bullet.h"
#include "Day24Enemy.h"
void Day24Scene::Init()
{
	Super::Init();
	Texture* backgroundTexture = Resource->LoadTexture(L"T_Background", L"Day24/Background.bmp");
	Resource->CreateSprite(L"S_Background", backgroundTexture);
	{
		GameObject* gameObject = new GameObject();
		gameObject->SetBody(CenterRect::MakeLTWH(0, 0, 1365, 616));
		{
			SpriteRenderer* component = new SpriteRenderer();
			SpriteRendererInfo info;
			info.SpriteKey = L"S_Background";
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}
		this->SpawnGameObject(gameObject);
	}
	this->SetCameraArea(CenterRect::MakeLTWH(0, 0, 1365, 616));

	{
		Day24Creature* gameObject = new Day24Creature();
		gameObject->Init();
		{
			CameraComponent* component = new CameraComponent();
			gameObject->AddComponent(component);
		}
		this->SpawnGameObject(gameObject);
		_creature = gameObject;
	}

	{
		GameObject* gameObject = new Day24Enemy();
		gameObject->Init();
		gameObject->SetPos({ 550, 200 });
		this->SpawnGameObject(gameObject);
	}

	//총알 진짜 생성되는지 테스트해보는 코드
	//{
	//	Day24Bullet* gameObject = new Day24Bullet();
	//	gameObject->Init();
	//	gameObject->SetPos({ 400, 400 });
	//	this->SpawnGameObject(gameObject);
	//}
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

#pragma region 방향키 인풋처리
	{
		Vector2 inputDir = {};
		if (Input->GetKey(KeyCode::W))
		{
			inputDir.y -= 1;
		}
		if (Input->GetKey(KeyCode::S))
		{
			inputDir.y += 1;
		}
		if (Input->GetKey(KeyCode::A))
		{
			inputDir.x -= 1;
		}
		if (Input->GetKey(KeyCode::D))
		{
			inputDir.x += 1;
		}
		inputDir = inputDir.Normalize();
		_creature->SetInputDir(inputDir);
	}
#pragma endregion

	

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Vector2 dir = Input->GetMousePosVector2() - _creature->GetSreenPos();
		dir = dir.Normalize();
		_creature->Shoot(dir);
	}

	if (Input->GetKeyDown(KeyCode::J))
	{
		_cameraPosition = { 500, 5 };
	}
}
void Day24Scene::Release()
{
	Super::Release();
}