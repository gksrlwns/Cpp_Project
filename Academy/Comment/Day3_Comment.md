﻿# Day 3
## 의사코드 (슈도 코드)
```
의사코드 : 만들려는 프로그램을 컴퓨터가 알아들을만한 어휘로 풀어서 설명하는 행위

아무리 간단한 프로그램이어도 수도코드가 존재
수도코드를 잘 작성하는 사람 = 코딩을 잘 하는 사람 일 수 밖에 없음

수도코드 작성하는 것을 습관화 하자

```

## 변수명, 함수명 규칙
```
변수 명 : 카멜케이스 (int myNumber)
함수 명 : 파스칼케이스 (int MyNumber):

상식 -> MS에서 C++ 변수는 스네이크 케이스(int my_number)를 지향하도록 문서에 작성되어 있음
``` 

## if문 규칙
```
*** 좋은 코드에서 제 1조건은 가독성
사람의 시선이 왼쪽에서 오른쪽
왼쪽에 작은 값, 오른쪽에 큰값을 넣는게 보편적으로 0.1초라도 읽는 속도를 빠르게 함
웬만하면 < 부등호로 사용 (실제 펄어비스 코딩 룰)
```

## 입출력 문법
``` cpp
c 언어
출력 - printf
입력 - scanf_s

cpp 언어
출력 - cout
입력 - cin
//printf(cout << "숫자를 입력해주세요");
cout << "숫자를 입력해주세요";
//scanf_s("%d", &inputNumber);
cin >> inputNumber;
```

## 랜덤
```
컴퓨터는 거짓말을 못함
다른 결과를 내거나, 속이거나 하는 행동 불가
rand()는 무작위 수를 뽑기위해 구현한 함수
미리 고정된 난수를 seed를 통해 통안에 숫자들을 순서대로 넣은걸 그대로 뽑아오는 결과

우리가 난수라고 느낄 수 밖에 없는 절대적인 값 = 현재 시간
현재시간 (ms)를 seed 값으로 넣음
 
srand(time(NULL)) //seed를 섞는 함수 

```