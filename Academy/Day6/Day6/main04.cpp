#include <iostream>

using namespace std;
enum class ERocksScissorPaper
{
	Rock,
	Scissor,
	Paper,
	End
};
void main()
{
	// 3. switch 문법
	//  - 안배워도 되는문법
	//  - if문으로 완벽하게 대체가능

	//  그런데 왜쓰냐??
	//  가독성때문

	// while 문 배운이유랑 같음
	// for문이 더 상위호환이지만
	// 가독성측면에서 달라집니다.

	// switch문
	int hand = (int)ERocksScissorPaper::Rock;
	switch ((ERocksScissorPaper)hand)
	{
		case ERocksScissorPaper::Rock:
			cout << "바위" << endl;
			break;

		case ERocksScissorPaper::Scissor:
			cout << "가위" << endl;
			break;

		case ERocksScissorPaper::Paper:
			cout << "보" << endl;
			break;

		default:
			cout << "잘못된값" << endl;
			break;
	}

	if (hand == (int)ERocksScissorPaper::Rock)
	{
		cout << "바위" << endl;
	}
	else if (hand == (int)ERocksScissorPaper::Scissor)
	{
		cout << "가위" << endl;
	}
	else if (hand == (int)ERocksScissorPaper::Paper)
	{
		cout << "보" << endl;
	}
	else
	{
		cout << "잘못된값" << endl;
	}

	//if문과 switch문의 차이점
	//if문은 조건식을 적는거라
	// 정수가 아니라 다른값이 들어올수있음
	//switch문은 정수만 적을수있습니다.
	// case 정수:

	// 그렇기때문에 제약사항이 더 붙어요 switch문은
	// 다만, 그 제약사항이 더 좋게 작용할떄가 많아서 사용합니다.
	//  + 가독성

	// 굳이 왜요?
	// 모든 프로그래머가 완벽하지 않아요.
	// 첫설계랑 다르게 작업하려는 프로그래머도 많고
	// 생각없이 코드짜는 사람 되게 많습니다.

	// 딱봐도 여기에는 이변수로만 제어하겠다라는 의미를 두면서
	// 땜빵코드질을 못하게하는

	// while문을 보면
	// ~~하는 동안 반복하겠구나

	// for문을 보면
	// 몇번 반복하겠구나

	// switch문을 보면
	// 저 값에 따라서 뭔가 이루어지겠구나

	// if문은 보면
	// 긴장합니다.
	// 끝까지 로직을 보게해요.
}