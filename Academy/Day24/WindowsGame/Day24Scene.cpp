#include "pch.h"
#include "Day24Scene.h"
void Day24Scene::Init()
{
	Super::Init();
}
void Day24Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day24Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day24Scene::Update()
{
	Super::Update();
}
void Day24Scene::Release()
{
	Super::Release();
}