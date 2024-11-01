#pragma once
class GameObject;
class Scene
{
protected:
	vector<GameObject*> _gameObjects;
	queue<GameObject*> _despawnObjectList;
	Vector2 _cameraPosition;
	CenterRect _cameraArea = {};
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
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
	void SetCameraArea(CenterRect area) { _cameraArea = area; }
	CenterRect GetCameraArea() { return _cameraArea; }

public:
	Scene() {}
	virtual ~Scene() {}

	
};

