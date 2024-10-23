#pragma once
class Component;
class GameObject
{
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

public:
	//게터, 세터
	inline CenterRect GetBody() { return _body; }
	inline void SetBody(CenterRect body) { _body = body; }

	inline string GetName() { return _name; }
	inline void SetName(string name) { _name = name; }

	inline Vector2 GetPos() { return _body.pos; }
	inline void SetPos(Vector2 pos) { _body.pos = pos; }

	inline void SetWidth(float width) { _body.width = width; }
	inline float GetWidth() { return _body.width; }

	inline void SetHeight(float height) { _body.height = height; }
	inline float GetHeight() { return _body.height; }

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
	virtual string ToString() { return ""; }

public:
	virtual void OnTriggerEnter(Collider* collider, Collider* other);
	virtual void OnTriggerExit(Collider* collider, Collider* other);
public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	template<typename T>
	T* GetComponent()
	{
		for (int i = 0; i < _components.size(); i++)
		{
			Component* component = _components[i];
			if (typeid(*component) == typeid(T))
			{
				T* result = dynamic_cast<T*>(component);
				if (result != nullptr)
				{
					return result;
				}
			}
		}
		return nullptr;
	}

public:
	GameObject() {}
	virtual ~GameObject() {}
};

