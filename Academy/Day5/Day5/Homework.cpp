#include <iostream>

using namespace std;

void main()
{
	//숫자야구 만들기
	//1. 컴퓨터가 랜덤으로 겹치지 않는 4자리 숫자를 고른다.
	// 4칸의 배열을 만든다.
	// 1번째 칸은 1-9까지의 랜덤한 숫자를 넣는다.
	// 2번째 칸은 0-9까지의 랜덤한 숫자 && 1번째 칸과 같지 않은 숫자를 넣는다.
	// 3번째 칸은 0-9까지의 랜덤한 숫자 && 1,2번째 칸과 같지 않은 숫자를 넣는다.
	// 4번째 칸은 0-9까지의 랜덤한 숫자 && 1,2,3번째 칸과 같지 않은 숫자를 넣는다.
	int numbersArray[4] = {};
	srand(time(NULL));
	while (true)
	{
		numbersArray[0] = rand() % 9;
		if (numbersArray[0] != 0)
		{
			break;
		}
	}

	for (int i = 1; i < 4; i++)
	{
		bool isSame = true;
		int index = 0;
		numbersArray[i] = rand() % 9;

		while (index < i)
		{
			if (numbersArray[i] == numbersArray[index])
			{
				numbersArray[i] = rand() % 9;
				index = 0;
				continue;
			}

			index++;

		}
	}
	for (int i = 0; i < 4; i++)
	{
		cout << numbersArray[i] << ",";
	}
	cout << endl;

	//2. 플레이어 9회 까지 게임을 플레이한다.
	// while(9)
	int count = 0;
	int playerNum[4] = {};

	while (count <= 9)
	{
		int ballCount = 0;
		int strikeCount = 0;
		cout << "4자리를 입력하세요." << endl;
		for (int i = 0; i < 4; i++)
		{
			cin >> playerNum[i];
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (playerNum[i] == numbersArray[j]) ballCount++;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (playerNum[i] == numbersArray[i])
			{
				strikeCount++;
				ballCount--;
			}
		}
		cout << "Strike : " << strikeCount << "  Ball : " << ballCount << endl;

		if (strikeCount == 4)
		{
			cout << "모두 맞혔습니다.";
			break;
		}
		count++;
	}


	//3. 자릿수와 숫자가 모두 일치하면 strike;
	// 숫자는 일치하지만 자릿수가 일치하지 않으면 ball;
	// 그것을 카운트하여 현황판을 출력

	//배열의 모든 값을 비교하여 ball인지 구분한다.
	//배열의 칸만 비교하여 strike인지 구분한다.
	




}