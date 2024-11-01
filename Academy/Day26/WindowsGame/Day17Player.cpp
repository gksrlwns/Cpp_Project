#include "pch.h"
#include "Day17Player.h"
#include "Day17Box.h"

void Day17Player::Init()
{
	_body = CenterRect(300, 100, 80, 80);
	_targetPoint = _body.pos;
}
void Day17Player::Render(HDC hdc)
{
	_body.Draw(hdc);
}
void Day17Player::Update()
{
	// Move
	/*if (InputManager::GetInstance()->GetKey(KeyCode::Left))
	{
		_body.pos.x -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Up))
	{
		_body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Right))
	{
		_body.pos.x += _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Down))
	{
		_body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}*/

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		_targetPoint = Input->GetMousePos();
	}

	// _targetPoint 방향으로 플레이어 움직이기

	// _targetPoint - 플레이어
	// 이게곧 방향벡터
	Vector2 dir = Vector2(_targetPoint.x - _body.pos.x, _targetPoint.y - _body.pos.y);

	if (1.0f < dir.Length())
	{
		dir = dir.Normalize();

		//방향 * 속도
		_body.pos.x += dir.x * _moveSpeed * Time->GetDeltaTime();
		_body.pos.y += dir.y * _moveSpeed * Time->GetDeltaTime();
	}



	//충돌체크
	RECT playerRect = _body.ToRect();
	CenterRect boxBody = _box->GetBody();
	RECT boxRect = boxBody.ToRect();
	RECT tmp;
	if (::IntersectRect(&tmp, &playerRect, &boxRect))
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom - tmp.top;

		//세로가 더길면
		if (width < height)
		{
			//좌측이나 우측에서 부딪힘.

			//Temp.Right가 Player의 Right와 같으면
			// = > Player의 우측부분이 부딪힘
			if (playerRect.right == tmp.right)
			{
				// 그만큼 밀려야겠죠.
				boxBody.pos.x += width;
			}
			// Temp.Left가 Player의 Left와 같으면
			// = > Player의 좌측 부분이 부딪힘
			else if (playerRect.left == tmp.left)
			{
				boxBody.pos.x -= width;
			}
		}
		else
		{
			if (playerRect.top == tmp.top)
			{
				boxBody.pos.y -= height;
			}
			else if (playerRect.bottom == tmp.bottom)
			{
				boxBody.pos.y += height;
			}
		}

		_box->SetBody(boxBody);
	}

}
void Day17Player::Release()
{

}