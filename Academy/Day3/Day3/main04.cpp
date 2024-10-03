#include <iostream>

using namespace std;

void main()
{
	// 새로운 문법
	// C에서의 출력과 입력은
	// printf
	// scanf_s

	// C++에서의 출력과 입력은
	// cout (부를때는 c out)
	// cin (부를때는 c in)
	// endl (부를때는 end line)
	// 이런함수가 추가됩니다.

	// %d, %f, %c 이런내용은 C++을 할거면 어쩌피쓰니까 배워야하는 내용이라

	int inputNumber = 0;
	//printf("숫자를 입력해주세요\n);
	cout << "숫자를 입력해주세요\n";

	//scanf_s("%d", &inputNumber);
	cin >> inputNumber;

	if (inputNumber % 2 == 0)
	{
		cout << "[" << inputNumber << "]" << "는 짝수입니다." << endl;
	}
	else
	{
		cout << "[" << inputNumber << "]" << "는 홀수입니다." << endl;
	}
}