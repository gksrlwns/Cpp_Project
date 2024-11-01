#include "pch.h"
#include "Day26Scene.h"
#include "Tilemap.h"
void Day26Scene::Init()
{
	Super::Init();


	//Tilemap 로드
	Tilemap* tilemap = Resource->LoadTilemap(L"TM_Test", L"Day26/map.txt");

	cout << tilemap->GetMapSize().x << "\t" << tilemap->GetMapSize().y << endl;
}
void Day26Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day26Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}
}
void Day26Scene::Update()
{
	Super::Update();
}
void Day26Scene::Release()
{
	Super::Release();
}