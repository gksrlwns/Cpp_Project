#include "pch.h"
#include "Day24Scene.h"
#include "Day24Creature.h"
void Day24Scene::Init()
{
	Super::Init();

	{
		Day24Creature* gameObject = new Day24Creature();
		gameObject->Init();
		this->SpawnGameObject(gameObject);
		_creature = gameObject;
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
	else
	{
		_creature->SetState(Day24CreatureState::Idle);
	}
}
void Day24Scene::Release()
{
	Super::Release();
}