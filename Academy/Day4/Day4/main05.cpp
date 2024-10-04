#include <iostream>

using namespace std;

void main()
{
	// 배열
	// 배열이란?

	// 가위바위보를 만들었는데,
	// 가위바위보하나빼기를 만들었다.
	// 한번에 내야하는 내용이 2개

	//따로 두개를 선언해주게됩니다.
	int playerLeftHand;
	int playerRightHand;

	// 나중에 기획자가 플레이어는 5개 낸것중에 한개를 선택할거에요.
	int playerChoiceHand1;
	int playerChoiceHand2;
	int playerChoiceHand3;
	int playerChoiceHand4;
	int playerChoiceHand5;

	// 이렇게 다섯개를 만들었다가 컨트롤 하기에는
	// 수정할 코드도 되게 많아지기 때문에..

	// 그래서 변수를 한번에 선언해주는 기능
	// 배열

	//자료형 변수명[길이] = {};
	int arr[10] = {};
	//사용
	// 프로그래밍은 항상 0부터 시작
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 10;

	cout << "arr[0] = " << arr[0] << endl;

	
	// 많이사용하는 알고리즘
	// Swap 알고리즘
	int a = 40;
	int b = 85;

	int temp;
	temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	// 반복문으로 넘어갔다가 다시 돌아올게요.
}