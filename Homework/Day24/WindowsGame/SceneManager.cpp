#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "DevScene.h"
#include "Day17Scene.h"
#include "Day18Scene.h"
#include "Day19Scene.h"
#include "Day20Scene.h"
#include "Day21Scene.h"
#include "Day22Scene.h"
#include "Day23Scene.h"
#include "Day24Scene.h"

void SceneManager::Init()
{

}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}


	if (_nextSceneType == SceneType::None)
	{
		return;
	}

	//==========================================
	//	## Change Scene Logic
	//==========================================
	
	// 1. 기존 씬 해제
	if (_scene)
	{
		_scene->Release();
	}

	// 2. 새로운씬을 생성
	Scene* newScene = this->CreateScene(_nextSceneType);
	
	// 3. 기존 씬포인터에 덮어쓰기
	SAFE_DELETE(_scene);
	_scene = newScene;
	_sceneType = _nextSceneType;
	_nextSceneType = SceneType::None;

	// 4. 새로운씬 초기화 
	newScene->Init();

}

void SceneManager::Release() 
{

}

Scene* SceneManager::CreateScene(SceneType sceneType)
{
	Scene* scene = nullptr;

	switch (sceneType)
	{
	case SceneType::None:
		break;
	case SceneType::DevScene:
		scene = new DevScene();
		break;
	case SceneType::Day17Scene:
		scene = new Day17Scene();
		break;
	case SceneType::Day18Scene:
		scene = new Day18Scene();
		break;
	case SceneType::Day19Scene:
		scene = new Day19Scene();
		break;
	case SceneType::Day20Scene:
		scene = new Day20Scene();
		break;
	case SceneType::Day21Scene:
		scene = new Day21Scene();
		break;
	case SceneType::Day22Scene:
		scene = new Day22Scene();
		break;
	case SceneType::Day23Scene:
		scene = new Day23Scene();
		break;
	case SceneType::Day24Scene:
		scene = new Day24Scene();
		break;
	default:
		break;
	}
	
	return scene;
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}

	_nextSceneType = sceneType;
}