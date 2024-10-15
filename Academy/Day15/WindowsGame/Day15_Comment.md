# Day 15
## C++ 형변환 종류 3가지
--- 
1. static_cast
 - 명시적 형변환
 - 장점 :불가능한 캐스팅은 애초에 에러를 띄워줌
 - 사용방식
 ```cpp
	float a = 3.3f;
	int b = static_cast<int>(a);
	//int b = (int)a; 와 같음
 ```
2. dynamic_cast
 - 클래스 형변환 (다운캐스팅, 업캐스팅)
 - 사용방식
 ```cpp
	Animal* animal = new Dog();
	Dog* dog = dynamic_cast<Dog*>(animal);
	if(dog != nullptr)
	{
		printf("dog is true\n");
	}
 ```

 3. reinterpret_cast (위험한 캐스팅 방식)
  - 포인터 형변환
  - 메모리배열을 유지하는 방식의 형변환
  - 사용방식ㅑ
```cpp
	// 일반적인 상황에서 사용하지않음.
	// 꼭 Document에서 제공해주면 그때 사용할것.
```

## 사각형과 사각형의 충돌체크
```
PtInRect를 4번하면 충돌체크 가능
- 사각형의 꼭짓점 4개 중 하나가 다른 사각형에 들어가 있는지 확인
```
## 클래스-02

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
- 클래스의 변수는 외부에서 수정 못하도록 막아줄 것.
함수를 통해서만 수정할 수 있도록

대부분하는 실수 상속 구조를 이쁘게 만들겠다고
``` cpp
class Unit
class SCV : Unit
class Marin : Unit
class Tank : Unit
```
이것은 좋은 상속 구조가 아님
프로그래머 입장에서는 모두 같은 Unit임 -> Type을 통해 다르게 구현
``` cpp
class Unit
{
	int UnitId ; //Type SCV인지, Tank인지
	vector <Skil> skilList; //미네랄 캐기, 시즈모드 돌입, 마인심기
}
```
- 간단한 밸런스 패치거나 간단한 유닛추가인데 프로그래머가 항상 참여를 하는 것은 아님
- 게임개발의 가장 이상적인 형태는 프로그래머가 그 게임이 뭔지 잘 모르는 형태
데이터로 게임이 돌아가게끔 만들어지는게 가장 좋은 형태

- 메이플 개발자라면
신규 월드에 신규 몬스터들이 생기는데
슬라임이랑 크게 다를 것 없이 이미지와 이름만 변경되면 됨
잘 만든 엑셀 시트 하나면 알아서 동작하도록 만들어주는 것이 생산성이 가장 좋다.

데이터 + 로직 형태의 프로그램으로 만드는게 가장 이상적.

## 객체지향 4가지 특징
### 캡슐화
- 변수를 private나 protected로 보호해서 아무나 접근하지 못하게 하는 것
- 캡슐화를 하는 이유는 변수를 아무데서나 수정할 수 있으면 그것은 객체가 아님
- 캡슐화가 수도코드의 첫걸음
``` cpp
class Computer
{
private :
	Ram _ram;
	Power _power;
public:
	void Boot(); // 부팅이라는 기능 아래에 ram이 활성화 되고 power가 켜짐
}
```
어쩔 수 없이 변수를 변경해줘야하는 경우 //Getter & Setter
- 참조를 찾기 쉬움
``` cpp
class Unit
{
private :
	float moveSpeed;
public :
	void Move();
	float GetMoveSpeed();
	void SetMoveSpeed(float moveSpeed);
}
```

