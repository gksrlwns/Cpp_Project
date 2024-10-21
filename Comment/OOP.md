# 객체지향
 
	 객체지향이 할말이 진짜많아요.

	 절차지향 프로그래밍
	 객체지향 프로그래밍

	 절차지향
	 하나의파일에서 위에서 아래로 쭉쓰는 느낌
	 

	 객체지향
	 클래스로 객체를 분리하여
	 객체끼리 서로 유기적으로 코드가 결합하여 실행하는 느낌

	  - 파일이 분리되니까?
	     - 유지보수가 편해지고
	  - 뭔가 객체(도메인)단위라서 
	     - 사업/기획이랑 말하기도 편해지고

	 더 좋게쓰려면 어떻게 써야하는가?

	 클래스에 이정도 내용은 꼭 지키자 하면서
	 기본적인 개념을 설명합니다.
## 클래스 기본 모토

- 캡슐화
- 추상화
- 상속
- 다형성

1. 캡슐화
 - 다른 곳에서 내 클래스 멤버변수를 수정하지 못하게 해라
 - 외부에 제공할것만 제공해라.

 - ★나머지는 내부에서 알아서 유기적으로 변하게 해줘라
    - 가장 쉬운 예시
    - 컴퓨터라는 클래스
       - 램, 파워, 모니터라는 변수
    - 부팅함수
        - 파워를 켜주고,
        - 파워에서 모니터한테 전력을 공급하고
        - 파워에서 램을 깨워주고
     저 내용을 사용자가 알아야 하냐는거에요. 

    

 - 외부로부터 데이터를 보호하는 것
 - 변수를 private나 protected로 만들라는 것

 - 그럼 변수를 수정하지 못하잖아요?
 - 변수 수정은 항상 클래스내부에서 이루어져야합니다.

 -> 왜?

 - 객체지향 파일로 분리해서 유지보수를 편하게 하자
 -> 외부에서 수정을하면
  - 우리 변수를 추가하고 제어하는데, 
  - 그 클래스만 확인하는게아니라 모든곳을 확인해줘야한다.
  - 어디에서든 그 변수가 바뀔수있기 때문에..

  코드 철학 측면에서도
   - 우리가 클래스라고하면 객체를 정의하는건데

   예를들어, 몬스터를 만든다고 쳐요.

   - 몬스터 Hp나 그런것들을 수정을 몬스터에서 

   OnDamaged라는 함수에서 Hp 깍는 기능을 제어해야하지

   플레이어 클래스에서 몬스터를 가져와서 몬스터의 Hp를 제어하는 행동은 기본적으로 좋은코드가 아닙니다.



객체지향 4대원칙에대해 설명하기전에
 - 이상론입니다.

 2. 상속
 ``` cpp
class Rabbit : Animal
{
};


class Animal
{
public:
    void Breathe();
    void Cry();
};
```
 - Rabbit은 기본적으로 Animal의 내용을 쓸수있다.
 - 재사용성이 있는 내용들은 상속을 통해서 잘써라
 3. 추상화, 다형성
 ``` cpp
class Dog : Animal
{
    void Breathe()
    {
        printf("멍멍");
    }
    void Cry()
    {
        printf("그르르르");
    }
};

class Cat : Animal
{
    void Breathe()
    {
        printf("야옹");
    }
    void Cry()
    {
        printf("미야");
    }
};


abstract class Animal
{
public:
    void Breathe();
    void Cry();
};

abstract -> 이 클래스는 실존하지는 않는 객체입니다.

 - 이 클래스는 단순하게 메서드만 제공해주고,
 - 실제구현은 상속받아서 정의해서 써라

 - 외부에서는 추상화 클래스만 들고 사용하면 되게 유리하다.

 Animal* arr[2] = {};

 arr[0] = new Cat();
 arr[1] = new Dog();

 for(int i = 0; i< 2; i++)
 {
    arr[i]->Update();
 }
 ```
 ## SOLID
SRP - 단일책임원칙
OCP - Open Closed Principle 개방 폐쇄원칙
LSP - 리스코프 치환 원칙
ISP - 인터페이스 어쩌구 원칙
DIP - 의존성 주입 원칙


SRP 
 [하나의 클래스에서 하나의 일만해라]
   - 어떤사람은 Player라고 클래스를 만들고
    - 여기에서 input이랑, 플레이어가 해야하는 모든 내용을 합니다.
   - 어떤사람은 PlayerInput, PlayerTrade, PlayerStunned 모두 클래스를 만들고
     - 각 클래스에서 인풋만, 거래만, 스턴걸렸을때 등등의 일들을 하나씩 처리합니다.

OCP
 - 확장은 편하게, 변경은 힘들게 코드짜라


[LSP, ISP, DIP]
 - 상속을 매우매우 잘알아야 설명드릴수있는 내용이라

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
