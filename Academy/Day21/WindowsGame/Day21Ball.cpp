#include "pch.h"
#include "Day21Ball.h"
#include "Day21Scene.h"
#include "Day21Paddle.h"
void Day21Ball::Init()
{
	Super::Init();

	_name = "ball";	 //딱히 어떤 역할을 하고있진 않음.
	_state = Day21BallState::Ready;

	Day21Scene* scene = dynamic_cast<Day21Scene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene != nullptr)
	{
		//_paddle = dynamic_cast<Day21Paddle*>(scene->FindGameObject("paddle"));
		_paddle = scene->GetPaddle();
	}
}

void Day21Ball::Render(HDC hdc)
{
	Super::Render(hdc);
}

void Day21Ball::Update()
{
	Super::Update();

	switch (_state)
	{
	case Day21BallState::Play:
		this->Update_Play();
		break;
	case Day21BallState::Ready:
		this->Update_Ready();
		break;
	}
}

void Day21Ball::Release()
{
	Super::Release();
}

void Day21Ball::Move(Vector2 dir)
{
	this->_body.pos += dir * _speed * Time->GetDeltaTime();
}

void Day21Ball::Update_Ready()
{
	// 1. 패들위에 고정
	if (_paddle == nullptr) return;

	float paddleTop = _paddle->GetBody().Top();
	float paddleX = _paddle->GetPos().x;

	this->_body = CenterRect(paddleX, paddleTop - _body.height / 2, _body.width, _body.height);

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 그방향으로 쏘면서 상태변경
		Vector2 mousePos = Input->GetMousePos();

		_dir = mousePos - _body.pos;
		_dir = _dir.Normalize();
		this->SetState(Day21BallState::Play);
	}

}
void Day21Ball::Update_Play()
{
	// 1. 내 진행방향대로 움직임
	this->Move(_dir);
}

string Day21Ball::ToString()
{
	/*string rv;
	{
		string info;
		info = format("body.pos.x : {0}\n", this->_body.pos.x);
	}
	{
		string info;
		info = format("body.pos.y : {0}\n", this->_body.pos.y);
		rv += info;
	}
	{
		string info;
		info = format("state : {0}\n", this->_state);
		rv += info;
	}*/
	string info;
	info = format("body.pos.x : {0}\n", this->_body.pos.x);
	

	return info;
}