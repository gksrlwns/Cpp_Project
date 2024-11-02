#include "pch.h"
#include "CameraComponent.h"
#include "Scene.h"
#include "GameObject.h"
void CameraComponent::Init()
{
	Super::Init();
}
void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CameraComponent::Update()
{
	Super::Update();

	Vector2 pos = this->GetOwner()->GetPos();

	//혹시 pos이 CameraArea을 넘었는지 확인
	// 넘었으면 Clamp 처리
	CenterRect cameraArea = CurrentScene->GetCameraArea();
	pos.x = clamp(pos.x, cameraArea.Left() + WIN_SIZE_X / 2, cameraArea.Right() - WIN_SIZE_X / 2);
	pos.y = clamp(pos.y, cameraArea.Top() + WIN_SIZE_Y / 2, cameraArea.Bottom() - WIN_SIZE_Y / 2);
	pos -= Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	CurrentScene->SetCameraPos(pos);
}
void CameraComponent::Release()
{
	Super::Release();
}