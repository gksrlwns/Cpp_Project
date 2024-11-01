#include "pch.h"
#include "Day21Ball.h"
#include "Day21Scene.h"
#include "Day21Paddle.h"
#include "Collider.h"
#include "Day21Brick.h"
#include "BoxCollider.h"
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

	//
	if (WIN_SIZE_X <= _body.Right())
	{
		//this->Move(-_dir); 
		//방향벡터는 길이가 1이되도록 유지해준다.
		//살짝의 난반사가 일어도록 조절
		Vector2 normalVector = Vector2(-1, 0) * 100 + Vector2(0, Random->GetFloat(0, 0));
		
		_dir = _dir.Reflect(normalVector.Normalize());
		_dir = _dir.Normalize();
	}

	if (_body.Left() <= 0)
	{
		//this->Move(-_dir); 
		//방향벡터는 길이가 1이되도록 유지해준다.
		Vector2 normalVector = Vector2(1, 0) * 100 + Vector2(0, Random->GetFloat(0, 0));

		_dir = _dir.Reflect(Vector2::Right());
		_dir = _dir.Normalize();
	}

	if (_body.Top() <= 0)
	{
		//this->Move(-_dir); 
		//방향벡터는 길이가 1이되도록 유지해준다.
		Vector2 normalVector = Vector2(0, -1) * 100 + Vector2(Random->GetFloat(0, 0), 0);

		_dir = _dir.Reflect(Vector2::Down());
		_dir = _dir.Normalize();
	}


	if (WIN_SIZE_Y <= _body.Bottom())
	{
		//패배처리 
		Alert(L"Alert", L"게임 패배");
		::PostQuitMessage(0);
	}

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

void Day21Ball::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	printf("Day21Ball::OnTriggerEnter\n");

	//충돌했을때 어떻게 처리할지.
	// 패들과 충돌했을떄 처리

	{
		//other의 정체가 paddle이면.
		Day21Paddle* paddle = dynamic_cast<Day21Paddle*>(other->GetOwner());
		if (paddle != nullptr)
		{
			//paddle일때 위에서 부딪혔으면. 
			// 옆만아니면되죠
			if (paddle->GetBody().Left() <= this->_body.Right() && this->_body.Left() <= paddle->GetBody().Right())
			{
				Vector2 normalVector = Vector2(0, 1) * 100 + Vector2(Random->GetFloat(0, 0), 0);
				_dir = _dir.Reflect(normalVector);
			}
		}
	}

	{
		//other의 정체가 brick이면.
		Day21Brick* brick = dynamic_cast<Day21Brick*>(other->GetOwner());
		if (brick != nullptr)
		{
			//정확하게 어디에 충돌했는지 체크가 필요합니다.
			BoxCollider* brickBoxCollider = dynamic_cast<BoxCollider*>(other);
			BoxCollider* myBoxCollider = dynamic_cast<BoxCollider*>(collider);
			if (brickBoxCollider != nullptr && myBoxCollider != nullptr)
			{
				//Box collider임.
				RECT brickRect = brickBoxCollider->GetCollision().ToRect();
				RECT ballRect = myBoxCollider->GetCollision().ToRect();
				ballRect.left -= 1;
				ballRect.top -= 1;
				ballRect.right += 1;
				ballRect.bottom += 1;
				RECT tmp;
				if(IntersectRect(&tmp, &brickRect, &ballRect))
				{
					printf("collision!\n");
					int width = tmp.right - tmp.left;
					int height = tmp.bottom - tmp.top;

					if (width < height)
					{
						// 옆으로 충돌했다.

						//왼쪽에서 충돌했으면
						if (tmp.right == ballRect.right)
						{
							_dir = _dir.Reflect(Vector2::Left());
							this->_body.pos.x -= width;
						}
						else
						{
							_dir = _dir.Reflect(Vector2::Right());
							this->_body.pos.x += width;
						}

					}
					else
					{
						//위아래로 충돌했다.

						//아래쪽에서 충돌했으면
						if (tmp.top == ballRect.top)
						{
							_dir = _dir.Reflect(Vector2::Down());
							this->_body.pos.y += height;
						}
						else
						{
							_dir = _dir.Reflect(Vector2::Up());
							this->_body.pos.y -= height;
						}
					}
				}
			}
			else
			{
				Alert(L"Error", L"Brick인데, BoxCollider가 아님");
			}


			GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnGameObject(brick);
		}
	}

}
void Day21Ball::OnTriggerExit(Collider* collider, Collider* other)
{
	Super::OnTriggerExit(collider, other);
	printf("Day21Ball::OnTriggerExit\n");
}