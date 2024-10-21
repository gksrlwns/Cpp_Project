# Day 9
## 빌드

C++, C#, JAVA(고급 언어)로 만들면 어셈블리 명령어로 바꿔주는 기능을 하는것이 Visual Studio의 빌드 기능

EXE 파일에 어떻게 실행한건지 어셈블리 명령어로 작성

32비트용, 64비트용, Mac Intel용, 실리콘용
CPU 칩에 의해서만 결정.

EXE를 실행하면 메모리 공간이 4개로 나누어짐.

- 코드영역 -> 어셈블리를 기억
- 데이터 영역 -> 전역 변수, static 변수 같은 기능을 기억
- Heap 영역 
	-> 동적 할당 할 때 쓰는 메모리 공간 (기본적으로 느림)
	-> 보통 여기에 덩치 큰 데이터를 넣음
- Stack 영역 
	-> 정적 할당할 때 쓰는 메모리 공간 (기본적으로 빠름)
	-> 보통 여기에 가벼운 데이터를 넣음

## Stack vs Heap

### Heap (동적 할당)
- 생성과 삭제를 프로그래머가 제어할 수 있음

#### 동적할당 방법
``` cpp
int* myPointer = nullptr;
myPointer = new int();
```
- new 자료형();
- 주솟값이 나오기 때문에 항상 포인터로 받아줘야한다.
- int* myPointer = new int();
#### 동적할당 삭제 방법
``` cpp
delete myPointer;
myPointer = nullptr;
```
- delete 주소값
- 주솟값을 담은 포인터는 더 이상 쓸모가 없으니 항상 nullptr로 초기화한다.

### Stack (지역 변수)
- 프로그래머가 삭제에 관여할 수 없음.
- 중괄호 끝나면 알아서 삭제

## Class vs Struct

최초의 설계자
기본 접근제어가 구조체는 public, 클래스는 private인가.
 -> C언어는 절차지향 프로그래밍, C++언어는 객체지향 프로그래밍


