#pragma once
class Sprite;
class Texture;
class Stone
{
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
public:
	void SetInfo(Vector2Int pos, StoneType type);
private:
	Vector2Int _pos = {};
	StoneType _type = StoneType::None;
	Texture* _texture = nullptr;
	Sprite* _sprite = nullptr;
};

