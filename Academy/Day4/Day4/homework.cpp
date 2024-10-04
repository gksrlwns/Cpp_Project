#include <iostream>

using namespace std;
void ShowHands(int hands, int user);
enum class RockScissorPaper
{
	Rock,
	Scissor,
	Paper,
	End
};
enum class User :int
{
	Player,
	Computer,
	End
};
void main()
{
	//1. 로또 번호 생성기
	//로또 1부터 45까지 숫자를 담을 배열을 생성한다.
	//로또 배열을 무작위로 섞어준다.
	//로또 배열중 랜덤한 숫자 7개를 뽑는다.

	int lotto[45] = {};
	int result[7] = {};
	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i+1;
	}

	cout << "Lotto 배열";
	for (int i = 0; i < 45; i++)
	{
		cout << lotto[i] << ",";
	}
	cout << endl;

	srand(time(NULL));
	

	for (int i = 0; i < 10000; i++)
	{
		int randomIndex1 = rand() % 45;
		int randomIndex2 = rand() % 45;

		int temp = lotto[randomIndex1];
		lotto[randomIndex1] = lotto[randomIndex2];
		lotto[randomIndex2] = temp;
	}
	cout << "Lotto 배열";
	for (int i = 0; i < 45; i++)
	{
		cout << lotto[i] << ",";
	}
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		int random = rand() % 45;
		result[i] = lotto[random];
	}

	cout << "로또 번호 : " ;
	for (int i = 0; i < 7; i++)
	{
		if( i == 6 ) cout << result[i];
		else cout << result[i] << ",";
	}
	cout << endl;


	//2. 가위바위보 하나 빼기
	//플레이어가 가위바위보 중 2개를 선택한다.
	//컴퓨터가 랜덤하게 가위바위보 중 2개를 선택하여 보여준다.
	//플레이어는 2개의 선택지 중에 하나를 선택한다.
	//컴퓨터는 2개의 선택지 중 하나를 무작위로 선택하여 보여준다.
	//IF(플레이어의)

	srand(time(NULL));
	printf("가위(0), 바위(1), 보(2) 중에서 2개를 선택해주세요\n");
	int playerHand = 0;
	int playerHands[2] = {};
	int comHand = 0;
	int comHands[2] = {};
	int choice = 0;
	for (int i = 0; i < 2; i++)
	{
		cout << "가위(0), 바위(1), 보(2) 중에서 선택해주세요" << endl;
		scanf_s("%d", &playerHands[i]);
		
	}

	for (int i = 0; i < 2; i++)
	{
		comHands[i] = rand() % (int)RockScissorPaper::End;
		ShowHands(comHands[i], (int)User::Computer);
	}

	for (int i = 0; i < 2; i++)
	{
		ShowHands(playerHands[i], (int)User::Player);
	}
	
	cout << "(1), (2) 선택한 2가지 중 하나를 선택해주세요" << endl;
	cin >> choice;
	
	if (choice == 1) playerHand = playerHands[0];
	else playerHand = playerHands[1];
	ShowHands(playerHand, (int)User::Player);

	comHand = comHands[rand() % 2];
	ShowHands(comHand, (int)User::Computer);

	// 승패 판정
	if (playerHand == comHand)
	{
		printf("비겼습니다.\n");
	}
	else if (playerHand == (int)RockScissorPaper::Scissor && comHand == (int)RockScissorPaper::Rock)
	{
		printf("졌습니다.\n");
	}
	else if (playerHand == (int)RockScissorPaper::Rock && comHand == (int)RockScissorPaper::Paper)
	{
		printf("졌습니다.\n");
	}
	else if (playerHand == (int)RockScissorPaper::Paper && comHand == (int)RockScissorPaper::Scissor)
	{
		printf("졌습니다.\n");
	}
	else
	{
		printf("이겼습니다.\n");
	}
}
void ShowHands(int hands,int user)
{
	if (user == 1)
	{
		// 컴퓨터 출력
		if (hands == (int)RockScissorPaper::Scissor)
		{
			printf("컴퓨터는 가위를 선택하셨습니다.\n");
		}
		else if (hands == (int)RockScissorPaper::Rock)
		{
			printf("컴퓨터는 바위를 선택하셨습니다.\n");
		}
		else if (hands == (int)RockScissorPaper::Paper)
		{
			printf("컴퓨터는 보를 선택하셨습니다.\n");
		}
	}
	else
	{
		// 플레이어 출력
		if (hands == (int)RockScissorPaper::Scissor)
		{
			printf("플레이어는 가위를 선택하셨습니다.\n");
		}
		else if (hands == (int)RockScissorPaper::Rock)
		{
			printf("플레이어는 바위를 선택하셨습니다.\n");
		}
		else if (hands == (int)RockScissorPaper::Paper)
		{
			printf("플레이어는 보를 선택하셨습니다.\n");
		}
	}
	
}

