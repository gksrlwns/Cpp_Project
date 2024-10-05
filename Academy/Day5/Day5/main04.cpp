#include <iostream>

using namespace std;

void main()
{
	// 반복문 
	// 3가지
	// for, while, do-while

	// 반복한다.
	// 반복하기 위해서 만들어진 문법

	// 사용법
	for (int i = 0; i < 1000; i++)
	{

	}
	// => 1000번 반복한다.
	// 주로 for문은 [i = 0; i++] 이 고정입니다.
	// 가독성측면에서
	// 코드를 보고 한글로 해석하는 행위
	// 아 1000번 반복하는 코드구나
	// 길이가 정해져있는 배열이랑 같이 쓰기 좋은것


	// while문
	/*bool isGamePlaying = true;
	while (isGamePlaying)
	{
		cout << "게임을 종료하겠습니까? (0 : 예, 그외 : 아니요)" << endl;
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}*/
	// => for문으로 변경하기
	//  while(조건식)
	//  {
	//     실행구문
	//  }

	// 조건식이 참이면
	// 실행구문을 실행한다
	// 
	// 조건식이 참이면
	// 실행구문을 실행한다
	// 
	// 조건식이 참이면
	// 실행구문을 실행한다
	//  
	
	// while은 그럼 보통 언제쓰는가?
	// 우리가 한글로 해석했을때, ~~하는 동안 이라는 느낌이나면 while을 씁니다.
	
	// for문은 => 몇 번
	// while문은 => ~~하는 동안

	//간단하게 실습
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	// => 이걸 while문으로 변경



	/*
	bool isGamePlaying = true;
	while (isGamePlaying)
	{
		cout << "게임을 종료하겠습니까? (0 : 예, 그외 : 아니요)" << endl;
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}
	*/

	//while(조건식)
	//{
	//	실행구문
	//}

	//for(선언식;조건식;증감식)
	//{
	//	실행구문
	//}

	/*bool isGamePlaying = true;
	for (;isGamePlaying;)
	{
		cout << "게임을 종료하겠습니까? (0 : 예, 그외 : 아니요)" << endl;
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}*/

	// 가독성이 많이많이 떨어집니다.



	/*
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	*/

	

	//for(선언식;조건식;증감식)
	//{
	//	실행구문
	//}

	//while(조건식)
	//{
	//	실행구문
	//}

	int i = 0;
	while (i < 10)
	{
		cout << i << endl;
		i++;
	}


	// 진짜 자주안쓰이는 반복문
	// do~while
	// 얘를 제가 언제 현업에서 마지막으로써봤냐

	// do
	// {
	//		실행구문
	// }while(조건식);

	// while문과 차이점이 딱하나있습니다.
	// 무조건 1번은 실행한다
	// 조건식이 일치하던 일치하지 않던

	// 종종 콘솔에서는 유의미하게 쓰입니다.
	int choice = 0;
	do
	{
		cout << "왼손(0)과 오른손(1)중에 선택해주세요." << endl;
		cin >> choice;
	} while (2 < choice || choice < 0);

	cout << "왼손(0)과 오른손(1)중에 선택해주세요." << endl;
	cin >> choice;
	while (2 < choice || choice < 0)
	{
		cout << "잘못 선택하셨습니다. 다시골라주세요." << endl;
		cin >> choice;
	}
}

