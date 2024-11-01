#include "pch.h"
#include "BoxRenderer.h"
#include "GameObject.h"
#include "Scene.h"
void BoxRenderer::Init()
{
	Super::Init();
}
void BoxRenderer::Render(HDC hdc)
{
	Super::Render(hdc);

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	CenterRect drawCenterRect = this->GetOwner()->GetBody();
	drawCenterRect.pos -= cameraPos;

	drawCenterRect.Draw(hdc, DRAWTYPE_RECT, _info.Brush);
}
void BoxRenderer::Update()
{
	Super::Update();
}
void BoxRenderer::Release()
{
	Super::Release();
}