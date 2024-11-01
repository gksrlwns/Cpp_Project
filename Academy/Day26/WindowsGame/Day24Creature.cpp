#include "pch.h"
#include "Day24Creature.h"
#include "BoxRenderer.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
#include "Day24Bullet.h"
#include "Scene.h"
void Day24Creature::Init()
{
	//4바이트 정수로 만들겠다.
	//R : 0~255 (unsigned char) - 1Byte
	//G : 0~255 (unsigned char) - 1Byte
	//B : 0~255 (unsigned char) - 1Byte
	//A(Alpha) : 0~255 (unsigned char) - 1Byte

	Texture* textureDown = Resource->LoadTexture(L"T_PlayerDown", L"Day24/PlayerDown.bmp", RGB(128,128,128));
	Texture* textureUp = Resource->LoadTexture(L"T_PlayerUp", L"Day24/PlayerUp.bmp", RGB(128, 128, 128));
	Texture* textureLeft = Resource->LoadTexture(L"T_PlayerLeft", L"Day24/PlayerLeft.bmp", RGB(128, 128, 128));
	Texture* textureRight = Resource->LoadTexture(L"T_PlayerRight", L"Day24/PlayerRight.bmp", RGB(128, 128, 128));

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
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureDown;
		Resource->CreateFlipbook(L"FB_character_2_3", info);
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
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureUp;
		Resource->CreateFlipbook(L"FB_character_2_0", info);
	}


	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_0_1", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_1_1", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureLeft;
		Resource->CreateFlipbook(L"FB_character_2_1", info);
	}


	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 0;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_0_2", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 1;
		info.Start = 0;
		info.End = 9;
		info.Loop = true;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_1_2", info);
	}
	{
		FlipbookInfo info;
		info.Duration = 1.0f;
		info.Line = 6;
		info.Start = 0;
		info.End = 10;
		info.Loop = false;
		info.Size = Vector2(200, 200);
		info.Texture = textureRight;
		Resource->CreateFlipbook(L"FB_character_2_2", info);
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
	case Day24CreatureState::Attack:
		Update_Attack();
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
	if (_inputDir != Vector2::Zero())
	{
		SetState(Day24CreatureState::Move);
	}
}

void Day24Creature::Update_Move()
{
	if (_inputDir == Vector2::Zero())
	{
		SetState(Day24CreatureState::Idle);
		return;
	}

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
void Day24Creature::Update_Attack()
{
	
	//  (나중에 엔진을 실제로 사용할때는)
	// 엔진기능으로도 부족해서
	// 툴을 새로 만듭니다.
	// 이거는 프로그래머보다 (기획 / 아트)에서 많이 사용하기때문에
	// 원하는 스펙대로 툴을 만들어서 줍니다. (스킬툴)
	// 
	// 스킬툴에 들어가는 내용들
	//   - 어떤 프레임에
	//     어떤 이벤트를 설정하고
	//     그 이벤트로 인해 어떤것들이 발동하는지 (소환을하는지, 힐을하는지, 광역데미지를 주는지 등)


	// 총알생성
	// 이 공격모션에 한번도 공격한적이 없고
	// 내가 원하는 Flipbook인덱스가 지나갔으면
	if(_isAttacked == false && 6 <= _flipbookRenderer->GetInfo().Index)
	{
		_isAttacked = true;
		Day24Bullet* gameObject = new Day24Bullet();
		gameObject->Init();
		Vector2 bulletPos = this->GetPos();
		switch (_dir)
		{
		case Day24CreatureDir::Up:
			bulletPos += Vector2::Up() * 80;
			break;
		case Day24CreatureDir::Left:
			bulletPos += Vector2::Left() * 80;
			break;
		case Day24CreatureDir::Right:
			bulletPos += Vector2::Right() * 80;
			break;
		case Day24CreatureDir::Down:
			bulletPos += Vector2::Down() * 80;
			break;
		default:
			break;
		}
		gameObject->SetPos(bulletPos);
		Day24BulletInfo info;
		info.Dir = _shootDir;
		info.Speed = 1000;
		gameObject->SetInfo(info);
		gameObject->SetState(EDay24BulletState::Move);
		CurrentScene->SpawnGameObject(gameObject);
	}


#pragma region 상태변환 AI
	// 1. 마지막 인덱스가 아니면 변경 불가능
	if (_flipbookRenderer->GetInfo().Index == _flipbookRenderer->GetInfo().LastIndex)
	{
		// 2. inputDir이 있으면 Move, 없으면 Idle
		if (_inputDir == Vector2::Zero())
		{
			SetState(Day24CreatureState::Idle);
		}
		else
		{
			SetState(Day24CreatureState::Move);
		}
	}
#pragma endregion

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


void Day24Creature::Shoot(Vector2 dir)
{
	// Validation Check
	if (_state == Day24CreatureState::Attack) return;

	// 1. 방향전환
	if (abs(dir.y) < abs(dir.x))
	{
		// 왼쪽이나 오른쪽 쳐다보도록
		if (dir.x < 0)
		{
			SetDir(Day24CreatureDir::Left);
		}
		else
		{
			SetDir(Day24CreatureDir::Right);
		}
	}
	else 
	{
		// 위나 아래 쳐다보도록
		if (dir.y < 0)
		{
			SetDir(Day24CreatureDir::Up);
		}
		else
		{
			SetDir(Day24CreatureDir::Down);
		}
	}

	//2. 관련된 변수 초기화
	_isAttacked = false;
	_shootDir = dir;

	//3. 공격모션으로 전환
	this->SetState(Day24CreatureState::Attack);
}

void Day24Creature::SetInputDir(Vector2 dir)
{
	if (_state == Day24CreatureState::Attack)
	{
		return;
	}

	_inputDir = dir;

	// SetDir 호출을 위한 작업

	if (false == EQUALS(_inputDir.x, 0))
	{
		// 왼쪽이나 오른쪽 쳐다보도록
		if (_inputDir.x < 0)
		{
			SetDir(Day24CreatureDir::Left);
		}
		else
		{
			SetDir(Day24CreatureDir::Right);
		}
	}
	else if (false == EQUALS(_inputDir.y, 0))
	{
		// 위나 아래 쳐다보도록
		if (_inputDir.y < 0)
		{
			SetDir(Day24CreatureDir::Up);
		}
		else
		{
			SetDir(Day24CreatureDir::Down);
		}
	}
}