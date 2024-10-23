#include "pch.h"
#include "DevScene.h"

void DevScene::Init()
{
}
void DevScene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"DevScene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void DevScene::Update()
{
}
void DevScene::Release()
{
}