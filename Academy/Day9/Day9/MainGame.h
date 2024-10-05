#pragma once
// 스네이크게임 풀이
#define GAME_TICK 100
struct Point
{
	int x;
	int y;
};
enum class EDirection
{
	Left,
	Up,
	Right,
	Down,
	End
};

class MainGame
{
public:
	void Init();
	void Run();
	void Release();

	void PrintBoard();
	void PrintSnake();
	void HideSnake();
	void PrintFood();
	void HideFood();
	void GenerateFood();
	void UpdateSnake(int tick);

public:
	bool _isGameExit = false;
	Point _boardSize = { 30, 20 };
	Point _snakePos[999] = { {15, 10}, };
	int _snakeLength = 1;
	EDirection _snakeDir = EDirection::Left;
	int _snakeTick = 200;
	int _snakeTickBackUp = 200;
	Point _food = { 0, 0 };
};

