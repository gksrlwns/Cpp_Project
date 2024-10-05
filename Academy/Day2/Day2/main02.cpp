﻿#include <iostream>
using namespace std;

void main()
{
	printf("Hello World!\n");
	// printf를 통해서 자기소개

	printf("제 이름은 백수영입니다.\n");
	printf("저는 95년생 입니다.\n");

	// 자기소개를 하는 프로그램
	// 사람마다, 이름이 다르고 태어난 년도가 다를거잖아요.

	// 입력값에 따라 다르게 출력되어야함.
	// 입력한걸 받는 방법도 알아야겠지만,
	// 사용자의 나이랑, 이름을 기억할수있는 수단

	// 게임 클라이언트
	//	레벨, 플레이어 닉네임, 데미지, 끼는장비

	// 프로그래밍에서는 무언가를 기억하기위해 변수라는 거를 생성합니다.
	
	// [변수]
	// @@이란 무엇인가?
	//		==> 변하는 수, 프로그램에서 무언가를 기억하는 방법.
	// @@을 왜쓰는가?
	//	=> 무언가를 기억하기위해 사용한다.
	// @@을 어떻게 사용하는가?
	

	// 변수 사용 방법
	// 공식 : 
	// 1. 자료형 변수명 = 값;
	// 2. 자료형 변수명;

	// 값 : 95, 백수영 과 같은 내용
	// 변수명 : 내가 앞으로 부를 이름 (프로그래머가 정해주는것)
	// 자료형 : 정수인지, 실수인지, 문자열인지 에 대한 정보

	// 자료형
	// int, float, char, bool
	// int : integer (정수)
	// float : 실수
	// char : character (문자)
	// bool : boolean (true, false)

	int year = 95;
	char name[100] = "백수영";

	//문자열이 조금 독특해요.
	// 아직은 외워주세요.
	//char => 문자열이 아니라 문자 a b c 같은 문자 하나만 담을수있어요.
	// 그래서 배열이라고하는 문법을통해 여러문자를 받을수있게끔 만들어준거에요.

	// 변수를 배웠다고해서, 
	//	저 year과 name을 출력할수있나요?
	// 그래서 변수를 출력하는 방법을 배우겠습니다.

	printf("우리가 원하는 글자 적기\n");
	// 변수를 출력하는 방법
	// 정수, 실수, 문자열, 문자 이거에따라 출력방법이 달라집니다.
	// 정수 : %d
	// 실수 : %f  (float)
	// 문자열 : %s  (string)
	// 문자 : %c   (char)

	//printf("%d", 변수);
	printf("year : %d\n", year);
	printf("name : %s\n", name);

	printf("year : %d, name : %s\n", year, name);

	// 실습 : 자기소개 
	//printf("제 이름은 백수영입니다.\n");
	//printf("저는 95년생 입니다.\n");
	// 해당내용을 변수로 바꿔서 출력하기 
	// 다른 내용도 3개 추가해주세요.

	// 실습시간 + 쉬는시간포함해서 8시에 다시 수업하겠습니다.

	// [빌드에서 제외하는방법]
	// main01.cpp(제외하고싶은 파일)우클릭 - 속성
	// 빌드에서 제외 => 예
	// 적용, 확인


	//실습
	int month = 8;
	int day = 12;
	float luck = 80.3;
	printf("오늘은 %d월 %d일 입니다.\n", month, day);
	printf("오늘의 운세는 %f점입니다.\n", luck);


}