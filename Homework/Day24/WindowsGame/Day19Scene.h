#pragma once
#include "Scene.h"

class Texture;
class Sprite;
class Day19Stone;

enum class Day19State
{
	BlackTurn,
	WhiteTurn,
	None
};

enum class Day19ErrorCode
{
	ERR_OK = 0,
	ERR_ALREADY_STONE_POS = 1,

};

class Day19Scene : public Scene
{
	DECLARE_CHILD(Day19Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
	
public:
	void Update_BlackTurn();
	void Update_WhiteTurn();

	//현재 마우스위치에 돌생성
	// 0 return => 돌생성 성공
	// 1~ return => 돌생성 실패
	int MakeStoneWithMousePos(int type);
	bool IsWin();
	wstring GetErrorCodeReason(int errorCode);

private:
	Texture* _backgroundTex = nullptr;
	Sprite* _background = nullptr;

	Day19Stone* _board[15][15];
	Vector2Int _lastPos = {};

	Vector2 _boardStartPos = { 24, 20 };
	Vector2 _cellSize = { 38.1f, 38.1f };
	Day19State _state = Day19State::None;
};

