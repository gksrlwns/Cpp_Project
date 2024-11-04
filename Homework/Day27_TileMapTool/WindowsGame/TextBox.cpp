#include "pch.h"
#include "TextBox.h"
#include "Scene.h"
#include "GameObject.h"
void TextBox::Init()
{
	Super::Init();
}
void TextBox::Render(HDC hdc)
{
	Super::Render(hdc);

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	CenterRect drawCenterRect = this->GetOwner()->GetBody();
	if (!_ignoreCamPos)
	{
		drawCenterRect.pos -= cameraPos;
	}

	drawCenterRect.Draw(hdc, DRAWTYPE_RECT, _info.Brush);
	Draw::Text(hdc, this->GetOwner()->GetPos().x, this->GetOwner()->GetPos().y, _text);
}
void TextBox::Update()
{
	Super::Update();
}
void TextBox::Release()
{
	Super::Release();
}