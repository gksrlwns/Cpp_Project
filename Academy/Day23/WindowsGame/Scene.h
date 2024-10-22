#pragma once
class GameObject;
class Scene
{
protected:
	vector<GameObject*> _gameObjects;
	queue<GameObject*> _despawnObjectList;
public:

//==========================================
//	## 기본함수
//==========================================
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnGameObject(GameObject* gameObject);
	void DespawnGameObject(GameObject* gameObject);

	GameObject* FindGameObject(string name);

public:
	Scene() {}
	virtual ~Scene() {}

};

