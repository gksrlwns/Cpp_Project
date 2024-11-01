#include "pch.h"
#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite(Texture* texture, int x, int y, int cx, int cy)
	: _texture(texture), _x(x), _y(y), _cx(cx), _cy(cy)
{
	/*_texture = texture;
	_x = x;
	_y = y;
	_cx = cx;
	_cy = cy;*/
}
HDC Sprite::GetDC()
{
	return _texture->GetDC();
}
int32 Sprite::GetTransparent()
{
	return _texture->GetTransparent();
}
Vector2Int Sprite::GetPos()
{
	return Vector2Int(_x, _y);
}
Vector2Int Sprite::GetSize()
{
	return Vector2Int(_cx, _cy);
}
void Sprite::Render(HDC hdc, int x, int y)
{
	//x, y 가 중앙위치가 되게끔 렌더링

	::TransparentBlt(hdc,
		x - this->GetSize().x / 2,
		y - this->GetSize().y / 2,
		this->GetSize().x,
		this->GetSize().y,
		this->GetDC(),
		this->GetPos().x,
		this->GetPos().y,
		this->GetSize().x,
		this->GetSize().y,
		this->GetTransparent()
	);
}
