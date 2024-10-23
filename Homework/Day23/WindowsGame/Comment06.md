## 1. 클래스-02

클래스 속성중에는
상속이 있습니다.


Pet, Npc 를 구현한다고 쳐요

```cpp
// struct나 class 로 만들겠죠

class Pet
{
	string _displayName;
	float _moveSpeed;
	int _price;
	int _petId;

public:
	//기능
	void Move();
	void Interaction();
	void Command(); // 명령어 수행
};

class Npc
{
	string _displayName;
	float _moveSpeed;
	int _npcId;

public:
	//기능
	void Move();
	void Interaction();
};

// 동일하게 기능이 겹치고, 그에따른 변수가 겹치는데
// 기획까지 동일한 내용으로 들어오면
// 코드를 재사용하는게 맞겠죠
// 상속을 통하여 코드를 재사용할수 있게 만들수있습니다.

// Pet과 Npc를 동일하게 받을수있는 공통 부모클래스를 만들어줘요


class Creature
{
private:
	string _displayName;
	float _moveSpeed;

public:
	void Move();
	void Interaction();
};


class Pet : public Creature
{
	int _price;
	int _petId;

public:
	void Command(); // 명령어 수행
};

class Npc : public Creature
{
	int _npcId;
};

```
