#include "pch.h"
#include "Day18Scene.h"

void Day18Scene::Init()
{
	Vector2 a = Vector2(-20, -20);
	Vector2 b = Vector2(1, 0);
	Vector2 c = a.Reflect(b);
	cout << "X : " << c.x << endl;
	cout << "Y : " << c.y << endl;

}
void Day18Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day18Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day18Scene::Update()
{

}
void Day18Scene::Release()
{
}