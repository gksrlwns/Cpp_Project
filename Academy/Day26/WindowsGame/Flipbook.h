#pragma once
#include "ResourceBase.h"

struct FlipbookInfo
{
	Texture* Texture;
	Vector2Int Size;
	int Start;
	int End;
	int Line;
	float Duration;
	bool Loop;
};

class Flipbook : public ResourceBase
{
	DECLARE_CHILD(Flipbook, ResourceBase);

public:
	void SetInfo(FlipbookInfo info) { _info = info; }
	FlipbookInfo GetInfo() { return _info; }

	void Render(HDC hdc, int x, int y);
	void Update();
protected:
	FlipbookInfo _info;

	int _index = 0;
	float _sumTime = 0.0f;

};

