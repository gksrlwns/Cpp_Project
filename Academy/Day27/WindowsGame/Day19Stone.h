#pragma once
class Day19Stone
{
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
public:
	void SetInfo(Vector2Int pos, int type);

	int GetType() { return _type; }
	Vector2Int GetPos() { return _pos; }
private:
	// 요 위치는 
	Vector2Int _pos = {};
	int _type = 0;		// 0 이면 흑돌, 1이면 백돌


	Vector2Int _boardStartPos = { 24, 20 };
	Vector2 _cellSize = { 38.1f, 38.1f };
};

