#include "MainGame.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void PrintXY(int x, int y, const char* str)
{
	GotoXY(x, y); cout << str;
}


void MainGame::Init()
{
	srand(time(NULL));

	cout << "스네이크 게임을 시작하겠습니다." << endl;

	//system("pause");
	for (int i = 5; i >= 0; i--)
	{
		Sleep(1000);
		cout << i << "초후에 시작하겠습니다." << endl;
	}
	GenerateFood();

	system("cls");
}

void MainGame::Run()
{
	PrintBoard();
	PrintSnake();
	PrintFood();
	int lastTick = GetTickCount64();
	while (_isGameExit == false)
	{
		if (GetTickCount64() - lastTick > GAME_TICK)
		{
			//0.1초 지났을때마다 하는 행동
			lastTick = GetTickCount64();
			this->UpdateSnake(GAME_TICK);
		}
	}
}

void MainGame::Release()
{

	cout << "스네이크 게임이 종료되었습니다." << endl;
}

void MainGame::PrintBoard()
{
	for (int i = 0; i < _boardSize.x; i++)
	{
		PrintXY(i * 2, 0, "■");
	}
	for (int i = 1; i <= _boardSize.y - 1; i++)
	{
		PrintXY(0, i, "■");
		PrintXY((_boardSize.x - 1) * 2, i, "■");
	}

	for (int i = 0; i < _boardSize.x; i++)
	{
		PrintXY(i * 2, _boardSize.y, "■");
	}
	
}

void MainGame::PrintSnake()
{
	for (int i = 0; i < _snakeLength; i++)
	{
		PrintXY(_snakePos[i].x * 2, _snakePos[i].y, "○");
	}
}
void MainGame::HideSnake()
{
	for (int i = 0; i < _snakeLength; i++)
	{
		PrintXY(_snakePos[i].x * 2, _snakePos[i].y, "ㅤ");
	}
}


void MainGame::PrintFood()
{
	PrintXY(_food.x * 2, _food.y, "★");
}
void MainGame::HideFood()
{

}
void MainGame::GenerateFood()
{
	_food.x = rand() % (_boardSize.x - 1) + 1;
	_food.y = rand() % (_boardSize.y - 1) + 1;
}

void MainGame::UpdateSnake(int tick)
{
	_snakeTick -= GAME_TICK;

	//1초에 한번씩 뱀이 이동한다.
	if (_snakeTick <= 0)
	{
		_snakeTick = _snakeTickBackUp;

		HideSnake();

		// 1번인덱스부터 length 까지는 
		// 자기보다 -1 인 인덱스 따라가게 해준다.
		for (int i = _snakeLength - 1; i >= 1; i--)
		{
			// 1
			// 4 -> 3
			_snakePos[i].x = _snakePos[i - 1].x;
			_snakePos[i].y = _snakePos[i - 1].y;
		}


		//머리를 이동방향대로 움직여준다.
		for (int i = 0; i < 1; i++)
		{
			switch (_snakeDir)
			{
			case EDirection::Left:
				_snakePos[i].x--;
				break;
			case EDirection::Up:
				_snakePos[i].y--;
				break;
			case EDirection::Right:
				_snakePos[i].x++;
				break;
			case EDirection::Down:
				_snakePos[i].y++;
				break;
			case EDirection::End:
				break;
			default:
				break;
			}


			if (_snakePos[0].x == _food.x && _snakePos[0].y == _food.y)
			{
				_snakeLength++;
				GenerateFood();
				PrintFood();
			}
		}

		PrintSnake();
	}



	if (_kbhit())
	{
		char inputKey = _getch();
		switch (inputKey)
		{
		case 'w':
			_snakeDir = EDirection::Up;
			break;
		case 'a':
			_snakeDir = EDirection::Left;
			break;
		case 's':
			_snakeDir = EDirection::Down;
			break;
		case 'd':
			_snakeDir = EDirection::Right;
			break;
		default:
			break;
		}
	}
}


// 숙제1 
// 섯다 룰모르시는분은 검색해주세요.
// 1:1로 컴퓨터랑 섯다 진행하는겁니다.

// 2장룰있고 3장룰있는데
// 2장룰로 해주시면됩니다.


// 숙제2
// 새로운 트럼프카드게임
// 1. 베팅을 합니다.
//	3장을 뽑을건데,
//	3번째 카드가 1번카드와 2번카드 사이의 값인지 맞추는 게임
//	1번카드가 10이고 2	번카드 3이다, 3번카드가 5
//	3번카드는 10과 2사이에 있으니 베팅합격 두배 돈땀.


