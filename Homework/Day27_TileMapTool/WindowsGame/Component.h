#pragma once
class GameObject;
class Component
{
protected:
	bool _isEnable = true;
	GameObject* _owner = nullptr;

public:
	void SetEnable(bool enable) { _isEnable = enable; }
	bool GetEnable() { return _isEnable; }

	void SetOwner(GameObject* owner) { _owner = owner; }
	GameObject* GetOwner() { return _owner; }

public:
	virtual void Init() {}
	virtual void Render(HDC hdc) {}
	virtual void Update() {}
	virtual void Release() {}
public:
	Component() {}
	virtual ~Component() {}
};

