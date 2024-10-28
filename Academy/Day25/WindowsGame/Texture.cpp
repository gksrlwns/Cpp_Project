#include "pch.h"
#include "Texture.h"
Texture* Texture::LoadBmp(const wstring& path)
{
	//1. 윈도우 핸들에 있는 DC를 가져온다.
	HDC hdc = ::GetDC(_hWnd);
	//2. 가져온 DC와 똑같은 DC를 만들어줍니다.
	_hdc = CreateCompatibleDC(hdc);
	//3. 파일을 로드해서 물감통에 넣는다.
	_bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (_bitmap == NULL)
	{
		MessageBox(_hWnd, path.c_str(), L"Image Load Failed", 0);
		return nullptr;
	}
	//3. 물감통을 DC에 적용한다.
	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap);
	//4. 기존에 적용되어있던 옛날물감은 삭제한다.
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}

void Texture::Render(HDC hdc, int x, int y)
{
	::TransparentBlt(hdc,
		x, 
		y, 
		this->GetSize().x, 
		this->GetSize().y, 
		this->GetDC(), 
		0, 
		0, 
		this->GetSize().x, 
		this->GetSize().y, 
		this->GetTransparent()
	);
}