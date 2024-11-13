#pragma once

enum class EDir
{
	Left = 0,
	Up,
	Right,
	Down,
};

class Board;
class Player
{
public:
	void Init(Board* board);
	void Update();

	Vector2Int GetPos() { return _pos; }
	bool CanGo(int x, int y);
	bool CanGo(Vector2Int pos) { return CanGo(pos.x, pos.y); }

	void CalulatePath_RightHand();
	void CalulatePath_BFS();
	void CalulatePath_DFS();
	void CalulatePath_Dijkstra();
	void CalulatePath_Astar();

public:
	Player() {}
	virtual ~Player() {}

private:
	Vector2Int _pos = {};
	EDir _dir = EDir::Right;

	Board* _board = nullptr;


	// 길찾기 알고리즘 후에 저장될 경로.
	vector<Vector2Int> _path = {};
	int _currentIndex = 0;
};

