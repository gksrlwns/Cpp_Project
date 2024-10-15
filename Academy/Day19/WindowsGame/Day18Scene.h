#pragma once
#include "Scene.h"

enum class Day18SceneState
{
	Ready,	// 공이 왼쪽이나 오른쪽벽에 붙어있음.
	Play,	// 공이 움직이면서 점수내기중
	None
};

class Day18Scene : public Scene
{
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	// 씬의 상태에 따라서 Update_Ready를 돌지, Update_Play를 돌지 결정한다.
	void Update_Ready();	
	void Update_Play();


public:
	void Update_Default();

private:
	CenterRect _ball = {};
	CenterRect _leftWall = {};
	CenterRect _rightWall = {};

	int _playerScore = 0;
	int _comScore = 0;

	Day18SceneState _state = Day18SceneState::None;
	bool _ballPosIsLeftWall = true;	// left wall에 붙어서 시작해야하나?

	float _wallSpeed = 500;
	bool _isRightWallMoveDirTop = true;

	Vector2 _ballDir = {};
	float _ballSpeed = 1000;
};


/*
시작할때 공은 왼쪽벽에 붙어있고,
   마우스를 클릭하면 그 방향으로 공이 날라간다.

*/


