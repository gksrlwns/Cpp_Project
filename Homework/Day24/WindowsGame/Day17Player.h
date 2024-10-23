#pragma once
class Day17Box;
class Day17Player
{
private:
	Day17Box* _box = nullptr;
	CenterRect _body;
	float _moveSpeed = 300.0f;

	Vector2 _targetPoint = {};

public:
	void Init();			// 생성될떄, 초기화해야할때.
	void Render(HDC hdc);	// 그림 그릴때,
	void Update();			// 매 프레임에 대한 로직
	void Release();			// 해제할때, 객체를 없앨때

public:
	void SetLinkBox(Day17Box* box) { _box = box; }

public:
	Day17Player() {}
	~Day17Player() {}
};

