#include <iostream>
#include <Windows.h>
//#define DEV_LOG
using namespace std;

void InitDeck(int card[]);
void PrintCard(int card);
void ShuffleCard(int card[]);
void PrintPlayerInfo(int playerGold);
void Bet(int& playerGold, int& choice, int& betMoney);
void TakeWinningMoney(int card, int betMoney, int choice, int& playerGold);
void SetNextGame(int& openCardIndex);
bool IsGamePlaying(int playerGold, int openCardIndex);
// 숙제풀이
// 하이로우 세븐
// ♤A ~ ♧K

// 52장

// 트럼프카드를 뭔가 조작을 할 수 있어야곘구나.
// 1. 트럼프카드 정의하기
// 2. 트럼프카드 출력하는거 구현하기
// 3. 트럼프카드 섞어보기

void main()
{
	srand(time(NULL));

	// 1. 트럼프카드 정의하기
	int card[52] = {};
	InitDeck(card);

	ShuffleCard(card);

#ifdef DEV_LOG
	for (int i = 0; i < 52; i++)
	{
		cout << i << "번째 트럼프카드 : " << endl;
		PrintCard(card[i]);
	}
#endif

	// 플레이어는 시작골드 10000원으로 시작
	int playerGold = 10000;
	cout << "플레이어가 입장하였습니다." << endl;

	bool isGamePlaying = true;
	int openCardIndex = 0;

	while(IsGamePlaying(playerGold, openCardIndex))
	{
		//1초기다리기
		Sleep(1000);
		//화면 지우기
		system("cls");

		//플레이어 정보 출력
		PrintPlayerInfo(playerGold);

		int choice = 0;
		int betMoney = 0;
		Bet(playerGold, choice, betMoney);

		//다음카드를 오픈
		cout << "카드오픈 : " << endl;
		PrintCard(card[openCardIndex]);

		//베팅정보에 따라 당첨금 추가
		TakeWinningMoney(card[openCardIndex], betMoney, choice, playerGold);
		
		// 다음턴을 위한 세팅
		SetNextGame(openCardIndex);
	}

	cout << "게임이 종료되었습니다. 남은골드 : " << playerGold << endl;
}

void InitDeck(int card[])
{
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}

	// 0 => ♤A
	// 1 => ♤2
	// 2 => ♤3
	// ...
	// 12 => ♤K
	// 13 => ◆A
	// 14 => ◆2
	// 15 => ◆3
	// ...
	// 25 => ◆K
	// 26 => ♥A
	// ...
	// 38 => ♥K
	// 39 => ♧A
	// ...
	// 51 => ♧K
}
void PrintCard(int card)
{

	switch (card / 13)
	{
	case 0:
		cout << "♤";
		break;
	case 1:
		cout << "◆";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "♧";
		break;
	default:
		break;
	}

	switch (card % 13 + 1)
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		cout << card % 13 + 1;
		break;
	}
	cout << endl;
}

void ShuffleCard(int card[])
{
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 52;
		int index2 = rand() % 52;
		//SwapCard(card[index1], card[index2]);
		int temp = card[index1];
		card[index1] = card[index2];
		card[index2] = temp;
	}
}

void PrintPlayerInfo(int playerGold)
{
	cout << "플레이어의 현재 골드 : " << playerGold << endl;
}

void Bet(int& playerGold, int& choice, int& betMoney)
{
	cout << "베팅을 진행해주세요." << endl;
	cout << "하이(0), 로우(1), 세븐(2) 중에 선택해주세요." << endl;

	cin >> choice;

	cout << "베팅 금액을 정해주세요." << endl;
	cin >> betMoney;
	while (playerGold < betMoney)
	{
		cout << "너무 많이 베팅하였습니다. 다시 베팅해주세요." << endl;
		cin >> betMoney;
	}

	playerGold -= betMoney;
}
void TakeWinningMoney(int card, int betMoney, int choice, int& playerGold)
{
	int number = card % 13 + 1;
	if (choice == 0)
	{
		if (7 < number)
		{
			cout << "축하합니다. 당첨금을 획득하였습니다." << endl;
			cout << "획득 골드 : " << betMoney * 2;
			playerGold += betMoney * 2;
		}
	}
	else if (choice == 1)
	{
		if (number < 7)
		{
			cout << "축하합니다. 당첨금을 획득하였습니다." << endl;
			cout << "획득 골드 : " << betMoney * 2;
			playerGold += betMoney * 2;
		}
	}
	else if (choice == 2)
	{
		if (number == 7)
		{
			cout << "축하합니다. 당첨금을 획득하였습니다." << endl;
			cout << "획득 골드 : " << betMoney * 10;
			playerGold += betMoney * 10;
		}
	}
}
void SetNextGame(int& openCardIndex)
{
	openCardIndex++;
}

bool IsGamePlaying(int playerGold, int openCardIndex)
{
	if (playerGold <= 0 || openCardIndex == 52)
	{
		return false;
	}

	return true;
}

// 숙제 2. 
// 하이로우세븐
// 
// 트럼프카드 52장으로 시작
// ♤A ~ ♥K 까지 존재
// 이 트럼프카드를 섞고

// 플레이어가 입장
// 플레이어는 시작골드 10000원으로 시작
// 베팅을하는데
// 다음카드가 7보다작은지, 7보다큰지, 7이랑 같은지 베팅
// 베팅금액따로 존재
// 
// 베팅을하고, 맞추면 
// 7보다작은지, 7보다큰지 => 2배 지급
// 7인걸 맞추면 => 10배 지급
// 
// 트럼프카드를 다쓰거나 플레이어가 파산나면 게임종료