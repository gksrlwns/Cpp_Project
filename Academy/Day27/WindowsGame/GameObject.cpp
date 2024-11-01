#include "pch.h"
#include "GameObject.h"
#include "Component.h"
#include "Collider.h"
#include "Scene.h"
void GameObject::Init()
{
}
void GameObject::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		if (false == component->GetEnable()) continue;

		component->Render(hdc);
	}
}
void GameObject::Update()
{
	for (Component* component : _components)
	{
		if (false == component->GetEnable()) continue;

		component->Update();
	}
}
void GameObject::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}

	_components.clear();
}

void GameObject::AddComponent(Component* component)
{
	if (component == nullptr) return;

	component->SetOwner(this);
	component->Init();
	_components.push_back(component);
}

void GameObject::RemoveComponent(Component* component)
{
	if (component == nullptr) return;
	
	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		Component* deleteComponent = *findIt;
		deleteComponent->Release();
		SAFE_DELETE(deleteComponent);
		_components.erase(findIt);
	}
}

void GameObject::OnTriggerEnter(Collider* collider, Collider* other)
{
	cout << "충돌 시작 : " << collider->GetOwner()->GetName().c_str() << " -> " << other->GetOwner()->GetName().c_str() << endl;
}
void GameObject::OnTriggerExit(Collider* collider, Collider* other)
{
	cout << "충돌 끝 : " << collider->GetOwner()->GetName().c_str() << " -> " << other->GetOwner()->GetName().c_str() << endl;
}

Vector2 GameObject::GetSreenPos()
{
	Vector2 pos = this->GetPos();
	pos -= CurrentScene->GetCameraPos();

	return pos;
}