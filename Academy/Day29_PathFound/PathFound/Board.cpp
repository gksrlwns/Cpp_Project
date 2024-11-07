#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Player.h"
void Board::Init(Player* player)
{
	_player = player;
	_size = 25;

	_mapInfo = vector<vector<TileType>>(_size,
		vector<TileType>(_size, TileType::Wall));

	this->GenerateMap();
}
void Board::GenerateMap()
{
	srand(time(NULL));
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_mapInfo[y][x] = TileType::Wall;
			}
			else
			{
				_mapInfo[y][x] = TileType::Empty;
			}
		}
	}

	//랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			// 벽지점은 안뚫도록 체크
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}
			
			//맨 아래에서는 하단벽 못지우게
			if (y == _size - 2)
			{
				if (x != _size - 2)
				{
					_mapInfo[y][x + 1] = TileType::Empty;
				}
				continue;
			}

			//맨 우측에서는 우측벽 못지우게
			if (x == _size - 2)
			{
				_mapInfo[y + 1][x] = TileType::Empty;
				continue;
			}

			int randomValue = rand() % 2;
			if (randomValue == 0)
			{
				//오른쪽길뚫기
				_mapInfo[y][x + 1] = TileType::Empty;
			}
			else
			{
				//아래길뚫기
				_mapInfo[y + 1][x] = TileType::Empty;
			}
		}
	}

	// 1, 1 위치를 startPos
	// _size-2, size-2 을 _exitPos
	_startPos = Vector2Int(1, 1);
	_exitPos = Vector2Int(_size - 2, _size - 2);
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (Vector2Int(x, y) == _player->GetPos())
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::BLACK);
				cout << "■";
				continue;
			}
			else if (Vector2Int(x, y) == _startPos)
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::PURPLE);
				cout << "■";
				continue;
			}
			else if (Vector2Int(x, y) == _exitPos)
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::PURPLE);
				cout << "■";
				continue;
			}

			switch (_mapInfo[y][x])
			{
			case TileType::Empty:
				ConsoleHelper::SetCursorColor(ConsoleColor::GREEN);
				break;
			case TileType::Wall:
				ConsoleHelper::SetCursorColor(ConsoleColor::WHITE);
				break;
			default:
				break;
			}
			cout << "■";
		}
		cout << endl;
	}
	ConsoleHelper::SetCursorColor(ConsoleColor::WHITE);
}