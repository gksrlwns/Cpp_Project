#include <iostream>
using namespace std;

//------------------
//	ENUM문 
//------------------
enum class ERockScissorPaper
{
	Rock,
	Scissor,
	Paper,
	End
};

//------------------
//	변수선언
//------------------
int myHand = 0;
int comHand = 0;

//------------------
//	함수선언
//------------------
void PrintMyHand()
{
	cout << "내가 낸것 : ";
	if (myHand == (int)ERockScissorPaper::Rock)
	{
		cout << "바위" << endl;
	}
	else if (myHand == (int)ERockScissorPaper::Scissor)
	{
		cout << "가위" << endl;
	}
	else if (myHand == (int)ERockScissorPaper::Paper)
	{
		cout << "보" << endl;
	}
}

void PrintComHand()
{
	cout << "상대가 낸것 : ";
	if (comHand == (int)ERockScissorPaper::Rock)
	{
		cout << "바위" << endl;
	}
	else if (comHand == (int)ERockScissorPaper::Scissor)
	{
		cout << "가위" << endl;
	}
	else if (comHand == (int)ERockScissorPaper::Paper)
	{
		cout << "보" << endl;
	}
}


void main()
{
	// 함수
	// void main()
	// {
	// }

	// 함수선언
	// void 함수명()
	// {
	//		함수내용
	// }

	// 함수호출 : 함수명();

	// 가위바위보
	// 
	// 내가 낼것 정하기
	// 컴퓨터가 낼것 정하기
	// 서로 낸것 보여주기


	cout << "내가 낼것을 골라주세요 (0 가위, 1바위, 2보)" << endl;
	// 내가 낼것 정하기
	cin >> myHand;

	srand(time(NULL));
	// 컴퓨터가 낼것 정하기
	comHand = rand() % 3;

	//수도코드대로 코드를 짤수있게됩니다.

	// 내가 낸것 보여주기

	//함수명();
	PrintMyHand();


	// 컴퓨가 낸것 보여주기
	PrintComHand();


	//함수는 여러줄있는거에 이름을 붙여준다고 생각하시면됩니다.


	//함수명 컨벤션
	//동사로 이름을 짓고

	//파스칼케이스 (대문자로시작해서 띄어쓰기부분마다 대문자로)
}

// 