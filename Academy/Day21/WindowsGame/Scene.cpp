#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
void Scene::Init()
{

}
void Scene::Render(HDC hdc)
{
	for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject == nullptr) continue;
		gameObject->Render(hdc);
	}
}
void Scene::Update()
{
	for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject == nullptr) continue;
		gameObject->Update();
	}
}
void Scene::Release()
{
	for (GameObject* gameObject : _gameObjects)
	{
		gameObject->Release();
		SAFE_DELETE(gameObject);
	}
	_gameObjects.clear();
}

void Scene::SpawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	_gameObjects.push_back(gameObject);
}
void Scene::DespawnGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	auto findIt = find(_gameObjects.begin(), _gameObjects.end(), gameObject);

	if (findIt != _gameObjects.end())
	{
		GameObject* deleteGameObject = *findIt;
		deleteGameObject->Release();
		SAFE_DELETE(deleteGameObject);
		_gameObjects.erase(findIt);
	}
}

GameObject* Scene::FindGameObject(string name)
{
	for (GameObject* gameObject : _gameObjects)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject;
		}
	}

	return nullptr;
}