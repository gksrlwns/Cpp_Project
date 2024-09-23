#pragma once

namespace Draw
{
	void Text(HDC hdc, int x, int y, wstring str);
	void Rectangle(HDC hdc, int x, int y, int width, int height);
	void Ellipse(HDC hdc, int x, int y, int width, int height);
}