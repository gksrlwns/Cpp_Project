#include "pch.h"
#include "Scene.h"

void Scene::Init()
{

}
void Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"CurrentScene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Scene::Update()
{
}
void Scene::Release()
{

}