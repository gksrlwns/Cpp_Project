#include "pch.h"
#include "Day17Scene.h"
#include "Day17Player.h"
#include "Day17Box.h"
void Day17Scene::Init()
{
	_player = new Day17Player();
	_player->Init();

	_box = new Day17Box();
	_box->Init();


	_player->SetLinkBox(_box);
	// 2가지방법
	// 1. Player에서 Box를 가져와서 
	//    Box를 미는 방식

	// 2. Box에서 Player를 가져와서
	//    밀리는 방식
}
void Day17Scene::Render(HDC hdc)
{
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day17Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}

	_box->Render(hdc);
	_player->Render(hdc);
}
void Day17Scene::Update()
{
	_box->Update();
	_player->Update();

	if (Input->GetKeyDown(KeyCode::Space))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Day18Scene);
	}
}
void Day17Scene::Release()
{
}