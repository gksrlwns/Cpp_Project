#pragma once
class Scene
{

//==========================================
//	## 기본함수
//==========================================
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	Scene() {}
	virtual ~Scene() {}

};

