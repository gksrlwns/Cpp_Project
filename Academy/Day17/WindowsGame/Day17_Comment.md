﻿# Day 17

## 1. 싱글톤
```
 싱글톤은 디자인패턴 중에 하나입니다.

 디자인 패턴이란?
  - 코딩해오면서 쌓은 노하우 코딩 방식
  - 코딩꼼수
  - 이렇게 코딩하니까 편하더라
 장점과 단점
  - 이렇게 코딩하니까 편하더라 << 장점
  - 단점이 있는 디자인 패턴들이 있습니다.
   (예를들면 객체지향을 헤친다던지 등등)
```

싱글톤이란?
```
 클래스 = 자료형
 그리고 비로소 변수로 선언을해야 객체가 됩니다.

 싱글톤은 프로그램 내에 객체를 1개만 두는 디자인 패턴

 싱글톤 객체라고하면 그 클래스는  
 프로그램에 한개밖에 존재를 안합니다.
```

장점
```
 그 클래스로 존재하는 객체는 하나만 있으니까
 어디에서든지, 그 클래스의 객체를 쉽게 가져올수있다.
```

단점
```
 객체 지향적이 못하다.
 객체 지향이라고하면 한 클래스에서 다른클래스를 안불러와야합니다.
 그렇지만 당연히 현업에서는 (특히 게임에서)
  그럴 수가 없어요.
  너무 이상적인 코딩입니다.
```
사용하는 이유 
```
 InputManager가 여러개 있으면 의미가 있을까요?
 오히려 싱글톤으로 한개만 존재하게 하고,

 어디에서든지 쉽게 접근할수있게 InputManager를 싱글톤으로 만든다.
```


**결과적으로 우리는 좋은 코드를 짜야합니다.**
 - 그러면 좋은 코드는 무엇인가?
     - 핵심을 관통하는 주제가 하나 있습니다.
         - 생산성
             - 이 코드가 보기좋은지 (남들이 보기에)
             - 이 코드를 수정하기 편하게 되어있는지
             - 이 코드에 추가기능을 넣을때 문제가 없는지

 - 객체 지향적이 못하다. << 이 주제
    - 생산성이랑 큰 관련이 있는데, 너무 특이케이스

 - 왜 생산성이 핵심이 되냐면
    - 비 개발자, 아니면 다른 사람이 보았을때 이사람이 잘하나?
      라는 관점으로 보면 볼 수 있는게 생산성 밖에 없습니다.
```cpp
class Singleton
{
public:
	static Singleton* GetInstence()
	{
		static Singleton instance;
		return &instance;
	}
private:
	Singleton(){}
	~Singleton() {}
};



```
## 헤더 선언
헤더에서 선언은 피하는게 좋고
클래스에서는 마음것 선언해도 좋음
- 이유 : C++은 기본적으로 빌드할 때 cpp 파일 단위로 빌드함.
         cpp 별로 따로따로 써야하는 내용들을 include 해줘야함
         하지만, 헤더는 cpp 파일에서 헤더만 include하고 헤더는 하는게 없음.
         헤더끼리 include해서 cpp 사용처끼리 순서가 꼬이면 빌드 에러가 발생함
         
``` cpp
//Game.h
class Day17Player; //클래스 선언
class Day17Box;//클래스 선언
class Game
{
	private:
	//Day17Player _player;	// 문제가 생긴이유는
							// 그래, Day17Player 이런 클래스가 있다는건 이제 알겠는데,
							// Day17Player 가 무엇인지 알아야 객체를 만들수 있는데, 지금 뭔지몰라.

	Day17Player* _player;	// 이렇게하면 문제가 안생겨요.
							// 포인터는 뭐죠? 메모리 주소
							// 결과적으로 포인터는 4바이트짜리 정수값
	Day17Box* _box; 
	};
}
```
## 자료형 재정의
``` cpp
using int8 = __int8; //C++에서 사용하는 예약어
typedef __int8 int8; //C 언어에서 사용하는 예약어
```

## define의 비밀
- 상수라고 안하고 매크로라고 언급한 이유
``` cpp
#define AAA (
#define PLUS +
#define BBB )
#define CCC(Name)\
private : Name(){}\
~Name(){}\


int a = AAA 1 PLUS 2 BBB;
//이렇게 해도 정상적으로 작동함
```
## TimeManager

```
 60FPS
 144FPS

 100ms 가 넘어간다.

 FPS -> 1초에 화면갱신이 몇번 되는지
 ms -> 이전 화면갱신부터 지금 화면갱신까지 몇ms가 걸렸는지
```

TimeManager는 단순하게
 이전업데이트 부터 현재 업데이트까지 걸린 시간을 재는게 TimeManager입니다.

기능으로는
```
 GetFps() -> 1초에 화면갱신이 몇번 되는지
 GetDeltaTime() -> 이전 화면갱신부터 지금 화면갱신까지 몇ms가 걸렸는지
```


## 게임수학-1
```
픽셀이 얼마나 움직이는지 (moveSpeed)

 방정식
 1s : speed(px) = deltaTime(s) : ??px 
 을 움직여야할까?

 speed * deltaTime = 1 * ??
 ?? = speed * deltatime
```