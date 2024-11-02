#pragma once
#include "Scene.h"

class Day24Creature;
class Day24Scene : public Scene
{
	DECLARE_CHILD(Day24Scene, Scene);

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	Day24Creature* _creature = nullptr;
};

