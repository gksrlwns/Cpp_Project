#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void GotoXY(int x, int y);

void main()
{
	// 진도 내용좀 바꾸겠습니다.

	// 다음금요일이 다음수업이어서
	// 숙제를 많이내야하는데,
	// 사실 콘솔에서 숙제를 낼만한게 크게 없어요.

	// 하나만 배우면 숙제를 낼게 많아지는데 그거를 배우겠습니다.

	// GotoXY


	cout << "출력" << endl;
	//system(" mode  con lines=50   cols=80 ");

	GotoXY(0, 0); cout << "┌────────────────────────────────────────────────────┐";
	GotoXY(0, 1); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 2); cout << "│ㅤㅤㅤ1. Play Gameㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 3); cout << "│ㅤㅤㅤ2. Exit Gameㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 4); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 5); cout << "│ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ│";
	GotoXY(0, 6); cout << "└────────────────────────────────────────────────────┘";

	GotoXY(20, 1); cout << "플레이어 골드 : 1000";

	GotoXY(3, 2);
	cout << "▶▷";
	int choice = 0;
	while (true)
	{

		if (_kbhit())	//키보드를 눌렀다면
		{
			char inputkey = _getch();	//누른값을 inputkey에 담겠다.
			GotoXY(3, 2 + choice);
			cout << "ㅤㅤ";	//기존거를 지워주고
			if (inputkey == 's')
			{
				choice++;
			}
			else if (inputkey == 'w')
			{
				choice--;
			}
			GotoXY(3, 2 + choice);
			cout << "▶▷";	// 새로 그 위치에 그린다.
		}
	}
}

// 콘솔창의 커서위치를 x, y로 변경해주겠다.
void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//숙제1.
// 그동안 만든것중에서
// 원하는거 1개 (오늘실습포함)
// GotoXY를 활용해서 꾸미기 

//숙제2.
// 오늘 실습한거 (몬스터와 플레이어 가위바위보)
// 시간내로 못하신분들 모두

//숙제3.
// 학생부 시스템
//1) 영어, 수학, 국어 성적 입력하게 끔해주고
//2) 입력을 모두했으면, 학생의 평균점수를 확인해주는 프로그램
// Gotoxy 써서 이쁘게하면 좋습니다.

//숙제4.
// 다마고치 / 스네이크게임 / 테트리스 게임중에 만들수있으신 분 한정해서 만들어와주세요.
// 기존게임과 달리 (사용자가 입력해야만 게임 진행)
// 리얼타임 게임
