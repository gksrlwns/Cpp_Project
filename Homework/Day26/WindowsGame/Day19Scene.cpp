#include "pch.h"
#include "Day19Scene.h"
#include "Texture.h"
#include "Sprite.h"
#include "Day19Stone.h"
void Day19Scene::Init()
{
	//T_Background 키값이 겹치면 안되니까 Texture를 쓸떄는 앞에 T_
	Texture* backgroundTexture = Resource->LoadTexture(L"T_Background", L"Day19/omok.bmp");
	//S_Background 키값이 겹치면 안되니까 Sprite를 쓸떄는 앞에 S_
	_background = Resource->CreateSprite(L"S_Background", backgroundTexture);

	Texture* blackStoneTexture = Resource->LoadTexture(L"T_BlackStone", L"Day19/bRock.bmp");
	Resource->CreateSprite(L"S_BlackStone", blackStoneTexture);
	Texture* whiteStoneTexture = Resource->LoadTexture(L"T_WhiteStone", L"Day19/wRock.bmp");
	Resource->CreateSprite(L"S_WhiteStone", whiteStoneTexture);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			_board[i][j] = nullptr;
		}
	}

	_state = Day19State::BlackTurn;
}
void Day19Scene::Render(HDC hdc)
{
	_background->Render(hdc, WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (_board[i][j] == nullptr)
			{
				continue;
			}
			_board[i][j]->Render(hdc);
		}
	}

}
void Day19Scene::Update()
{

	switch (_state)
	{
	case Day19State::BlackTurn:
		Update_BlackTurn();
		break;
	case Day19State::WhiteTurn:
		Update_WhiteTurn();
		break;
	case Day19State::None:
		break;
	default:
		break;
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (_board[i][j] == nullptr)
			{
				continue;
			}
			_board[i][j]->Update();
		}
	}
}
void Day19Scene::Release()
{

}


void Day19Scene::Update_BlackTurn()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		int result = MakeStoneWithMousePos(0);
		if (result == 0)
		{
			_state = Day19State::WhiteTurn;
		}
		else
		{
			Alert(L"Error Code", GetErrorCodeReason(result).c_str());
		}

		//승패판정
		bool isWin = IsWin();

		if (isWin)
		{
			Alert(L"게임끝", L"흑돌 승리");
			::PostQuitMessage(0);
		}
	}
}
void Day19Scene::Update_WhiteTurn()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		int result = MakeStoneWithMousePos(1);
		if (result == 0)
		{
			_state = Day19State::BlackTurn;
		}
		else
		{
			Alert(L"Error Code", GetErrorCodeReason(result).c_str());
		}

		//승패판정
		bool isWin = IsWin();

		if (isWin)
		{
			Alert(L"게임끝", L"백돌 승리");
			::PostQuitMessage(0);
		}
	}
}

int Day19Scene::MakeStoneWithMousePos(int type)
{
	Vector2Int mousePos = Input->GetMousePos();
	int x = mousePos.x - _boardStartPos.x;
	int y = mousePos.y - _boardStartPos.y;

	int cellX = x / _cellSize.x;
	int cellY = y / _cellSize.y;

	if (_board[cellY][cellX] != nullptr)
	{
		return static_cast<int>(Day19ErrorCode::ERR_ALREADY_STONE_POS);
	}

	//쌍삼 쌍사체크
	// 승패판정하는거에서 하나쯤은 공백이 있어도 가능함
	// 쌍삼은 둘다막는거아니면 쌍삼 인정으로 체크하면되겠죠

	_board[cellY][cellX] = new Day19Stone();
	_board[cellY][cellX]->Init();
	_lastPos = Vector2Int(cellX, cellY);
	_board[cellY][cellX]->SetInfo(_lastPos, type);
	

	return static_cast<int>(Day19ErrorCode::ERR_OK);
}

wstring Day19Scene::GetErrorCodeReason(int errorCode)
{
	switch ((Day19ErrorCode)errorCode)
	{
	case Day19ErrorCode::ERR_OK :
		return L"정상입니다.";

	case Day19ErrorCode::ERR_ALREADY_STONE_POS:
		return L"해당 위치에 돌이 이미 있습니다.";
	}
}

bool Day19Scene::IsWin()
{
	//_lastPos 기준으로 그 돌이 이겼는지만 판단해준다.

	//1. 가로검사
	{
		int type = _board[_lastPos.y][_lastPos.x]->GetType();
		Vector2Int checkPos = Vector2Int(_lastPos.x - 1, _lastPos.y);
		int count1 = 0;
		// 가로 왼쪽이 공백이 나올떄까지.
		while (true)
		{
			if (checkPos.x < 0)
			{
				break;
			}

			//현재 돌이 없거나
			if (_board[checkPos.y][checkPos.x] == nullptr)
			{
				break;
			}

			//다른 돌일 경우
			if (_board[checkPos.y][checkPos.x]->GetType() != type)
			{
				break;
			}


			checkPos.x--;
			count1++;
		}

		checkPos = Vector2Int(_lastPos.x + 1, _lastPos.y);
		int count2 = 0;
		// 가로 오른쪽이 공백이 나올떄까지.
		while (true)
		{
			if (15 <= checkPos.x)
			{
				break;
			}

			//현재 돌이 없거나
			if (_board[checkPos.y][checkPos.x] == nullptr)
			{
				break;
			}

			//다른 돌일 경우
			if (_board[checkPos.y][checkPos.x]->GetType() != type)
			{
				break;
			}


			checkPos.x++;
			count2++;
		}

		if (count1 + count2 == 4)
		{
			return true;
		}
	}

	return false;
}