#include "pch.h"
#include "CommonFunction.h"

namespace Draw
{
	void Text(HDC hdc, int x, int y, wstring str)
	{
		::TextOut(hdc, x, y, str.c_str(), str.length());
	}
	void Rectangle(HDC hdc, int x, int y, int width, int height)
	{
		::Rectangle(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	}
	void Ellipse(HDC hdc, int x, int y, int width, int height)
	{
		::Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	}

	void Rectangle(HDC hdc, RECT rc)
	{
		::Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
}

namespace Collision
{
	bool PtInRect(POINT pt, RECT rc)
	{
		if (rc.left <= pt.x && pt.x <= rc.right)
		{
			if (rc.top <= pt.y && pt.y <= rc.bottom)
			{
				return true;
			}
		}

		return false;
	}

	bool RectInRect(RECT rc1, RECT rc2)
	{
		POINT pt1 = { rc1.left, rc1.top };
		POINT pt2 = { rc1.right, rc1.top };
		POINT pt3 = { rc1.left, rc1.bottom };
		POINT pt4 = { rc1.right, rc1.bottom };
		POINT pt5 = { rc2.left, rc2.top };
		POINT pt6 = { rc2.right, rc2.top };
		POINT pt7 = { rc2.left, rc2.bottom };
		POINT pt8 = { rc2.right, rc2.bottom };

		if (PtInRect(pt1, rc2) || PtInRect(pt2, rc2) || PtInRect(pt3, rc2) || PtInRect(pt4, rc2)
			|| PtInRect(pt5, rc1) || PtInRect(pt6, rc1) || PtInRect(pt7, rc1) || PtInRect(pt8, rc1))
		{
			return true;
		}

		return false;
	}

	bool RectInRect(CenterRect centerRect1, CenterRect centerRect2)
	{
		RECT rc1 = centerRect1.ToRect();
		RECT rc2 = centerRect2.ToRect();

		POINT pt1 = { rc1.left, rc1.top };
		POINT pt2 = { rc1.right, rc1.top };
		POINT pt3 = { rc1.left, rc1.bottom };
		POINT pt4 = { rc1.right, rc1.bottom };
		POINT pt5 = { rc2.left, rc2.top };
		POINT pt6 = { rc2.right, rc2.top };
		POINT pt7 = { rc2.left, rc2.bottom };
		POINT pt8 = { rc2.right, rc2.bottom };

		if (PtInRect(pt1, rc2) || PtInRect(pt2, rc2) || PtInRect(pt3, rc2) || PtInRect(pt4, rc2)
			|| PtInRect(pt5, rc1) || PtInRect(pt6, rc1) || PtInRect(pt7, rc1) || PtInRect(pt8, rc1))
		{
			return true;
		}

		return false;
	}
}