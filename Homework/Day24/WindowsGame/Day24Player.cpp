#include "pch.h"
#include "Day24Player.h"
#include "FlipbookRenderer.h"
void Day24Player::Init()
{
	Super::Init();

	this->SetBody(CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
	{
		_flipbookRenderer = new FlipbookRenderer();
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_right_move";
		_flipbookRenderer->SetInfo(info);
		this->AddComponent(_flipbookRenderer);
	}

}
void Day24Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Day24Player::Update()
{
	Super::Update();

	switch (_state)
	{
	case Day24PlayerState::None:
		break;
	case Day24PlayerState::Idle:
		break;
	case Day24PlayerState::Move:
		Move();
		break;
	}
}
void Day24Player::Release()
{
	Super::Release();
}
void Day24Player::Move()
{
	this->_body.pos += _dir * speed * Time->GetDeltaTime();
}

void Day24Player::SetDir(Vector2 dir)
{
	if (_dir == dir)
	{
		return;
	}
	_dir = dir;
	// UP 일때
	if (EQUALS(dir.x, 0) && EQUALS(dir.y, -1))
	{
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_up_move";
		_flipbookRenderer->SetInfo(info);
	}

	if (EQUALS(dir.x, 0) && EQUALS(dir.y, 1))
	{
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_down_move";
		_flipbookRenderer->SetInfo(info);
	}
	if (EQUALS(dir.x, -1) && EQUALS(dir.y, 0))
	{
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_left_move";
		_flipbookRenderer->SetInfo(info);
	}
	if (EQUALS(dir.x, 1) && EQUALS(dir.y, 0))
	{
		FlipbookRendererInfo info;
		info.FlipbookKey = L"FB_character_right_move";
		_flipbookRenderer->SetInfo(info);
	}

}