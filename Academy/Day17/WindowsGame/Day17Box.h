#pragma once
class Day17Box
{
public:
	Day17Box() {}
	~Day17Box() {}

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

public:
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }
private:
	CenterRect _body;
};