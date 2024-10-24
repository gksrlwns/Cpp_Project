#include "pch.h"
#include "Day24Creature.h"
#include "BoxRenderer.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
void Day24Creature::Init()
{
	Texture* textureDown = Resource->LoadTexture(L"T_PlayerDown", L"Day24/PlayerDown.bmp");
	Texture* textureUp = Resource->LoadTexture(L"T_PlayerUp", L"Day24/PlayerUp.bmp");

	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_0_3", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_1_3", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_0_0", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_1_0", info);
	}



	this->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 100));
	{
		FlipbookRenderer* component = new FlipbookRenderer();
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_0_3";
		component->SetInfo(info);
		this->AddComponent(component);
		_flipbookRenderer = component;
	}

	this->SetFlipbook();

	Super::Init();
}

void Day24Creature::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day24Creature::Update()
{
	Super::Update();

	switch (_state)
	{
	case Day24CreatureState::Idle:
		Update_Idle();
		break;
	case Day24CreatureState::Move:
		Update_Move();
		break;
	default:
		break;
	}
}

void Day24Creature::Release()
{
	Super::Release();
}

void Day24Creature::Update_Idle()
{

}

void Day24Creature::Update_Move()
{
	switch (_dir)
	{
	case Day24CreatureDir::Up:
		this->_body.pos += Vector2::Up() * _speed * Time->GetDeltaTime();
		break;
	case Day24CreatureDir::Left:
		this->_body.pos += Vector2::Left() * _speed * Time->GetDeltaTime();
		break;
	case Day24CreatureDir::Right:
		this->_body.pos += Vector2::Right() * _speed * Time->GetDeltaTime();
		break;
	case Day24CreatureDir::Down:
		this->_body.pos += Vector2::Down() * _speed * Time->GetDeltaTime();
		break;
	default:
		break;
	}
}

void Day24Creature::SetState(Day24CreatureState state)
{
	if (_state == state)
	{
		return;
	}
	_state = state;
	this->SetFlipbook();

}
void Day24Creature::SetDir(Day24CreatureDir dir)
{
	if (_dir == dir)
	{
		return;
	}

	_dir = dir;
	this->SetFlipbook();
}

void Day24Creature::SetFlipbook()
{
	if (_flipbookRenderer == nullptr)
	{
		return;
	}

	FlipbookRendererInfo info;
	info.FlipbookKey = format(L"FB_character_{0}_{1}", (int)_state, (int)_dir);
	_flipbookRenderer->SetInfo(info);

}