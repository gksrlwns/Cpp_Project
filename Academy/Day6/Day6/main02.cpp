#include <iostream>
using namespace std;

//매크로
#define NUMBER_SIZE 3
//#define DEV_MODE


//ctrl + r + r
int computerNumber[NUMBER_SIZE] = {};
int userNumber[NUMBER_SIZE] = {};
bool isUserNumberComplete = false;
int strike = 0;
int ball = 0;

// 함수전방선언
void ChooseComputerNumber();
void ChooseUserNumber();
void CheckValidationUserNumber();
void CompareNumbers();
void PrintStrikeBallCount();
void InitUserVariable();
void main()
{
	// 숫자야구 (4자리)
	// 수도코드 
	// 
	// 가장 간단한 룰
	// 
	// 1. 컴퓨터가 랜덤숫자를 뽑는다. (4자리)
	// 2. 유저가 랜덤숫자를 외친다.
	// 3. 그 외친숫자가 올바른 숫자인지 판단한다.
	// 4. 올바른 숫자라면 5번으로, 올바르지 않은 숫자라면 2번으로 간다.
	// 5. 외친숫자와 컴퓨터가 정한 숫자를 비교하여 Ball, Strike를 센다.
	// 6. strike, ball을 출력한다.
	// 7. 2~6번을 9번 반복한다. 혹시 그안에 정답을 입력하면 게임을 종료한다.

	// 가장간단한 룰 형태를 함수로 바꿔볼게요
	// 1. ChooseComputerNumber();
	// 2. ChooseUserNumber();
	// 3. CheckValidationUserNumber();
	// 4.  - 
	// 5. CompareNumbers();
	// 6. PrintStrikeBallCount();

	srand(time(NULL));
	ChooseComputerNumber();
	for (int i = 0; i < 9; i++)
	{
		while (isUserNumberComplete == false)
		{
			ChooseUserNumber();
			CheckValidationUserNumber();
		}
		CompareNumbers();
		PrintStrikeBallCount();

		if (strike == NUMBER_SIZE)
		{
			break;
		}

		InitUserVariable();
	}
	
}

void ChooseComputerNumber()
{
	// 컴퓨터가 랜덤으로 겹치지 않는 4자리 숫자를 고른다. (이때 첫번째 자리는 무조건 1이상이어야함)
	// ex. 1777(x), 1789(o), 2154(o), 2155(x), 0124(x), 1204(o)
	//  이 기능에대한 수도코드
	// 랜덤숫자를 뽑는방법

	// 그냥 1000 ~ 9999 까지 랜덤숫자뽑아서
	// 각자릿수가 안겹치는지 체크하는방법

	// arr[10]을 만들고 0 ~9 까지 넣어둔다음
	// 배열을 섞은다음에
	// 첫번째자리가 0만안되게 잘뽑기


	// arr[10]을 만들고 0 ~9 까지 넣어둔다음
	int arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	// 배열을 섞은다음에
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	// 첫번째자리가 0만안되게 잘뽑기
	if (arr[0] == 0)
	{
		//뒤에서부터 4개뽑는다
		//천의 자릿수 arr[9]
		//백의 자릿수 arr[8]
		//십의 자릿수 arr[7] 
		//일의 자릿수 arr[6]
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			computerNumber[i] = arr[9 - i];
		}
	}
	else
	{
		//천의 자릿수 arr[0]
		//백의 자릿수 arr[1]
		//십의 자릿수 arr[2] 
		//일의 자릿수 arr[3]
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			computerNumber[i] = arr[i];
		}
	}

#ifdef DEV_MODE
	cout << "[디버깅용] 입력한 computerNumber : ";
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		cout << computerNumber[i];
	}
	cout << endl;
#endif
}

void ChooseUserNumber()
{
	// 2. 유저가 랜덤숫자를 외친다.
	// 플레이어는 회마다 겹치지 않는 숫자를 부른다. (이때 첫번째 자리는 무조건 1이상이어야함)
	// ex. 1777(x), 1789(o), 2154(o), 2155(x), 0124(x), 1204(o)

	int tempNumber;
	cout << "부를 숫자를 입력해주세요 : ";

	//이거는 사용성이 너무 떨어집니다.
	//cin >> userNubmer[0];
	//cin >> userNubmer[1];
	//cin >> userNubmer[2];
	//cin >> userNubmer[3];

	cin >> tempNumber;
	// 1234 / 1000 => 1
	// 1234 / 100 => 12 % 10 => 2
	//userNumber[0] = tempNumber / 1000 % 10;
	//userNumber[1] = tempNumber / 100 % 10;
	//userNumber[2] = tempNumber / 10 % 10;
	//userNumber[3] = tempNumber / 1 % 10;

	// 반복문으로 처리가능하겠다.
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int length = NUMBER_SIZE - 1 - i;
		int divNumber = 1;
		for (int j = 0; j < length; j++)
		{
			divNumber *= 10;
		}
		userNumber[i] = tempNumber / divNumber % 10;
	}


#ifdef DEV_MODE
	cout << "[디버깅용] 입력한 userNumber : ";
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		cout << userNumber[i];
	}
	cout << endl;
#endif

}
void CheckValidationUserNumber()
{
	//유저가 입력한게 어래 조건을 충족하면 
	// isUserNumberComplete = true로 바꿔주고
	//그렇지 않으면 isUserNumberComplete = false로 설정한다.
	// 
	// [조건]
	// 겹치지 않는 숫자를 부른다. (이때 첫번째 자리는 무조건 1이상이어야함)
	// ex. 1777(x), 1789(o), 2154(o), 2155(x), 0124(x), 1204(o)
	//

	// 1. 각자릿수별로 for문을 돈다.
	// 2. 각 자리에서 그 다음자릿수들을 for문을 또 돈다.

	//userNumber[0] ~ userNumber[4]
	isUserNumberComplete = true;
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int checkNumber1 = userNumber[i];
		for (int j = i + 1; j < NUMBER_SIZE; j++)
		{
			int checkNumber2 = userNumber[j];

			if (checkNumber1 == checkNumber2)
			{
				isUserNumberComplete = false;
			}
		}
	}


	//첫번째자릿수는 0이면 안됨.
	if (userNumber[0] == 0)
	{
		isUserNumberComplete = false;
	}

	// userNumber[0], userNumber[1]
	// userNumber[0], userNumber[2]
	// userNumber[0], userNumber[3]

	// userNumber[1], userNumber[2]
	// userNumber[1], userNumber[3]

	// userNumber[2], userNumber[3]
}

void CompareNumbers()
{
	// 5. 외친숫자와 컴퓨터가 정한 숫자를 비교하여 Ball, Strike를 센다.
	//수도코드
	// computerNumber를 순회하고 => 이변수를 currentComputerNumber
	// userNumber를 순회한다. => 이변수를 currentUserNumber
	// 만약 currentComputerNumber == currentUserNumber 이면
	//		만약 computerNumber를 순회한 인덱스 == userNumber를 순회한 인덱스와 같다면
	//			strike++;
	//		그렇지 않으면
	//			ball++;

	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int currentComputerNumber = computerNumber[i];
		for (int j = 0; j < NUMBER_SIZE; j++)
		{
			int currentUserNumber = userNumber[j];

			if (currentComputerNumber == currentUserNumber)
			{
				if (i == j)
				{
					strike++;
				}
				else
				{
					ball++;
				}
			}
		}
	}

}

void PrintStrikeBallCount()
{
	cout << strike << "스트라이크, " << ball << "볼!" << endl;
}


void InitUserVariable()
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		userNumber[i] = 0;
	}

	isUserNumberComplete = false;
	strike = 0;
	ball = 0;
}