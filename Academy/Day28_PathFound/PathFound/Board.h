#pragma once

enum class TileType
{
	Wall,
	Empty
};

class Board
{
public:
	Board() {}
	virtual ~Board() {}

public:
	void Init();
	void GenerateMap();
	void Render();

private:
	int _size = 0;
	vector<vector<TileType>> _mapInfo;
};

