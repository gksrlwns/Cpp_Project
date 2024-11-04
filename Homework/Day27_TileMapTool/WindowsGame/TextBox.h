#pragma once
#include "BoxRenderer.h"

class TextBox : public BoxRenderer
{
	DECLARE_CHILD(TextBox, BoxRenderer);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetText(wstring text) { _text = text; }
	wstring GetText() { return _text; }
	void SetIgnoreCamPos(bool ignoreCamPos) { _ignoreCamPos = ignoreCamPos; }
	bool GetIgnoreCamPos() { return _ignoreCamPos; }
private:
	wstring _text;
	bool _ignoreCamPos = false;
};

