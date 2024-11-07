#pragma once

enum class TileType
{
	Wall,
	Empty
};

class Player;
class Board
{
public:
	Board() {}
	virtual ~Board() {}

public:
	void Init(Player* player);
	void GenerateMap();
	void Render();

public:
	Vector2Int GetStartPos() { return _startPos; }
	Vector2Int GetExitPos() { return _exitPos; }
	TileType GetTileType(int x, int y) { return _mapInfo[y][x]; }
	int GetSize() { return _size; }

private:
	int _size = 0;
	vector<vector<TileType>> _mapInfo;

	Vector2Int _startPos;
	Vector2Int _exitPos;

	Player* _player;
};

