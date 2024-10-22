#include "pch.h"
#include "BoxRenderer.h"
#include "GameObject.h"

void BoxRenderer::Init()
{
	Super::Init();
}
void BoxRenderer::Render(HDC hdc)
{
	Super::Render(hdc);
	this->GetOwner()->GetBody().Draw(hdc, DRAWTYPE_RECT, _info.Brush);
}
void BoxRenderer::Update()
{
	Super::Update();
}
void BoxRenderer::Release()
{
	Super::Release();
}