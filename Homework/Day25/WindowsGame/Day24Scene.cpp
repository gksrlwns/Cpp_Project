#include "pch.h"
#include "Day24Scene.h"
#include "Day24Creature.h"
#include "SpriteRenderer.h"
#include "BoxRenderer.h"
#include "CameraComponent.h"
#include "Day24Bullet.h"
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
		GameObject* gameObject = new GameObject();
		gameObject->Init();
		{
			BoxRenderer* component = new BoxRenderer();
			BoxRendererInfo info;
			info.Brush = GRAY_BRUSH;
			component->SetInfo(info);
			gameObject->AddComponent(component);
		}
		gameObject->SetBody(CenterRect(550, 200, 80, 80));
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

	if (Input->GetKey(KeyCode::W))
	{
		_creature->SetDir(Day24CreatureDir::Up);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::S))
	{
		_creature->SetDir(Day24CreatureDir::Down);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::A))
	{
		_creature->SetDir(Day24CreatureDir::Left);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::D))
	{
		_creature->SetDir(Day24CreatureDir::Right);
		_creature->SetState(Day24CreatureState::Move);
	}
	else
	{
		_creature->SetState(Day24CreatureState::Idle);
	}

	//게임오브젝트가 Input을 가지고있을일이 없다고생각하셔도 무방합니다.
	// 플레이어니까 플레이어에서 인풋받아서 하고싶은데요?
	// 나중에 네트워크 들어가면
	// 내캐릭터도 플레이어
	// 상대방캐릭터도 플레이어
	// 플레이어 안에서 Input코드가 있으면
	// 둘다 움직이는 기괴한 버그가 나옵니다.
	// isMine 이런변수둬서 따로처리해야하거든요
	// 그것도 Scene에서 Key Input받고 원하는 객체로 행동을 하도록 명령넣어주는게 더 말이되죠
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Vector2 dir = Input->GetMousePosVector2() - _creature->GetPos();
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