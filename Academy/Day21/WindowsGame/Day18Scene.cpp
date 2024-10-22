#include "pch.h"
#include "Day18Scene.h"

void Day18Scene::Init()
{
	_ball = CenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 20, 20);
	_leftWall = CenterRect::MakeLTWH(0, WIN_SIZE_Y / 2 - 150, 30, 300);
	_rightWall = CenterRect::MakeLTWH(WIN_SIZE_X - 30, WIN_SIZE_Y / 2 - 150, 30, 300);

	_state = Day18SceneState::Ready;
	_ballPosIsLeftWall = true;
	_isRightWallMoveDirTop = true;
}
void Day18Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day18Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	_ball.Draw(hdc, DRAWTYPE_ELIPSE);
	_leftWall.Draw(hdc);
	_rightWall.Draw(hdc);


	{
		wstring scoreStr = ::format(L"{} : {}", _playerScore, _comScore);
		Draw::Text(hdc, WIN_SIZE_X - 100, 0, scoreStr);
	}



	{
		wstring stateStr = ::format(L"state : {}", (int)_state);
		Draw::Text(hdc, WIN_SIZE_X - 100, 30, stateStr);
	}

}
void Day18Scene::Update()
{
	Update_Default();

	switch (_state)
	{
	case Day18SceneState::Ready:
		Update_Ready();
		break;
	case Day18SceneState::Play:
		Update_Play();
		break;
	case Day18SceneState::None:
		break;
	default:
		break;
	}
}
void Day18Scene::Release()
{
}

void Day18Scene::Update_Default()
{
	// 1. 키 입력에 따라 왼쪽 벽 위치 움직임.
	if (Input->GetKey(KeyCode::W))
	{
		_leftWall.pos.y -= _wallSpeed * Time->GetDeltaTime();

		_leftWall.pos.y = ::clamp(_leftWall.pos.y,
			0 + _leftWall.height / 2,
			WIN_SIZE_Y - _leftWall.height / 2);
	}

	if (Input->GetKey(KeyCode::S))
	{
		_leftWall.pos.y += _wallSpeed * Time->GetDeltaTime();

		_leftWall.pos.y = ::clamp(_leftWall.pos.y, 
			0 + _leftWall.height / 2,
			WIN_SIZE_Y - _leftWall.height / 2);
	}


	// 2. 오른쪽벽이 패트롤하고있어야함.
	if (_isRightWallMoveDirTop)
	{
		_rightWall.pos.y -= _wallSpeed * Time->GetDeltaTime();

		if (_rightWall.Top() < 0)
		{
			_isRightWallMoveDirTop = false;
		}
	}
	else
	{
		_rightWall.pos.y += _wallSpeed * Time->GetDeltaTime();

		if (WIN_SIZE_Y < _rightWall.Bottom())
		{
			_isRightWallMoveDirTop = true;
		}
	}
}

void Day18Scene::Update_Ready()
{
	//1. 공이 왼쪽이나 오른쪽벽에 붙어있어야함.
	if (_ballPosIsLeftWall)
	{
		// 공을 왼쪽 벽 좌표에 붙여준다.
		_ball.pos = Vector2(
			_leftWall.pos.x + _leftWall.width / 2 + _ball.width / 2,
			_leftWall.pos.y
		);
	}
	else
	{
		// 공을 오른쪽 벽 좌표에 붙여준다.
		_ball.pos = Vector2(
			_rightWall.pos.x - (_rightWall.width / 2 + _ball.width / 2),
			_rightWall.pos.y
		);
	}

	//2. 볼이 발사되어야함.
	if (_ballPosIsLeftWall)
	{
		if (Input->GetKeyDown(KeyCode::RightMouse))
		{
			//플레이어가 좌표를 지정해줌
			_ballDir = Vector2(Input->GetMousePos()) - _ball.pos;
			//방향벡터는 길이가 항상 1이어야한다.
			_ballDir = _ballDir.Normalize();

			_state = Day18SceneState::Play;
		}
	}
	else
	{
		if (Input->GetKeyDown(KeyCode::RightMouse))
		{
			//랜덤좌표를 지정받음.
			_ballDir = Vector2(rand() % WIN_SIZE_X, rand() % WIN_SIZE_Y) - _ball.pos;
			//방향벡터는 길이가 항상 1이어야한다.
			_ballDir = _ballDir.Normalize();

			_state = Day18SceneState::Play;
		}
	}

}
void Day18Scene::Update_Play()
{
	//1. 볼이 방향대로 움직어야합니다.
	_ball.pos += _ballDir * _ballSpeed * Time->GetDeltaTime();

	//2. 볼이 벽에 튕기면 반사되어야합니다.
	if (_ball.Top() < 0)
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir = _ballDir.Reflect(Vector2::Down());
		printf("_ballDir : %f, %f\n", _ballDir.x, _ballDir.y);
	}
	else if (WIN_SIZE_Y < _ball.Bottom())
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir = _ballDir.Reflect(Vector2::Up());
	}

	//3. 볼이 왼쪽벽에 부딪히면
	if (Collision::RectInRect(_leftWall, _ball) && _leftWall.Right() < _ball.pos.x)
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir = _ballDir.Reflect(Vector2::Right());
	}

	//4. 볼이 오른쪽쪽벽에 부딪히면
	if (Collision::RectInRect(_rightWall, _ball) && _ball.pos.x < _rightWall.Left())
	{
		_ball.pos -= _ballDir * _ballSpeed * Time->GetDeltaTime();
		_ballDir = _ballDir.Reflect(Vector2::Left());
	}


	//5. 공이 왼쪽으로 넘어가면
	if (_ball.Left() < 0)
	{
		_comScore++;
		_state = Day18SceneState::Ready;
		_ballPosIsLeftWall = true;
	}

	if (WIN_SIZE_X < _ball.Right())
	{
		_playerScore++;
		_state = Day18SceneState::Ready;
		_ballPosIsLeftWall = false;
	}
}
