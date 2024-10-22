#include "pch.h"
#include "Day21Paddle.h"

void Day21Paddle::Init()
{
	Super::Init();

	_name = "paddle";	 //딱히 어떤 역할을 하고있진 않음.
}

void Day21Paddle::Render(HDC hdc)
{
	Super::Render(hdc);

	//_body.Draw(hdc);
}

void Day21Paddle::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::A))
	{
		this->Move(Vector2::Left());
	}

	if (Input->GetKey(KeyCode::D))
	{
		this->Move(Vector2::Right());
	}
}

void Day21Paddle::Release()
{
	Super::Release();
}

void Day21Paddle::Move(Vector2 dir)
{
	this->_body.pos += dir * _speed * Time->GetDeltaTime();
	this->_body.pos.x = clamp(this->_body.pos.x, this->GetWidth() / 2, WIN_SIZE_X - this->GetWidth() / 2);
}