#include "pch.h"
#include "Day20Scene.h"
void Day20Scene::Init()
{
	for (int i = 0; i < 100; i++)
	{
		cout << Random->GetInt(0, 10) << endl;
	}
}
void Day20Scene::Render(HDC hdc)
{
	{
		wstring nameStr = ::format(L"Day20Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day20Scene::Update()
{

}
void Day20Scene::Release()
{

}