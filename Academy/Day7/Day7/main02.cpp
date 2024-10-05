#include <iostream>

#define BINGO_SIZE 7
#define BINGO_ARRAY_SIZE (BINGO_SIZE * BINGO_SIZE)
#define DEV_LOG

using namespace std;

//--------------------------------
//	변수 정의
//--------------------------------
int myBingo[BINGO_ARRAY_SIZE] = {};
int comBingo[BINGO_ARRAY_SIZE] = {};
int calledNumber = 0;
int turn = 1;
int myBingoCount = 0;
int comBingoCount = 0;
bool isGamePlaying = true;

void MakeBoard();
void ShuffleBoard();
void PrintBoard();
void CallBingoNumber();
void MarkBingoNumber();
void GoToNextTurn();
void CheckBingoCount();

void main()
{
	// 1. 빙고 - 숙제풀이

	// 빙고의 수도코드
	// 1. 내 빙고판과 컴퓨터 빙고판 정의
	//  myBingo[25] = {1 ~ 25} , comBingo[25] = {1 ~ 25}
	// 2. 빙고판 셔플. (나, 컴퓨터)
	// 3. 빙고판을 출력 (나, 컴퓨터) (출력할떄 -1은 X가 나오도록 조정)
	// [내턴]
	// 4. 내가 숫자를 하나 부른다.
	// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
	// (-1이 삭제라고 우리끼리 룰을 정한거입니다.)
	// [상대턴]
	// 6. 컴퓨터가 숫자를 하나 부른다.
	// 7. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
	// (-1이 삭제라고 우리끼리 룰을 정한거입니다.)
	// 8. 4번으로 돌아가서 내용을 반복한다.

	srand(time(NULL));
	// 1. 내 빙고판과 컴퓨터 빙고판 정의
	MakeBoard();
	//2. 빙고판 셔플. (나, 컴퓨터)
	ShuffleBoard();
	while (isGamePlaying)
	{
		// 3. 빙고판을 출력 (나, 컴퓨터)
		PrintBoard();
		// 4. 내가 숫자를 하나 부른다.
		CallBingoNumber();
		// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
		MarkBingoNumber();
		// 6. 턴 변경
		GoToNextTurn();

		// 7. 빙고카운트 체크
		CheckBingoCount();
		// 8. 내 빙고카운트가 3이상히면 내가 승리, 게임종료
		
		if (3 <= myBingoCount || 3 <= comBingoCount)
		{
			isGamePlaying = false;
		}
	}

	PrintBoard();
	if (comBingoCount == myBingoCount)
	{
		cout << "무승부입니다." << endl;
	}
	else if (comBingoCount < myBingoCount)
	{
		cout << "플레이어가 승리하였습니다." << endl;
	}
	else
	{
		cout << "컴퓨터가 승리하였습니다." << endl;
	}

}

// 1. 내 빙고판과 컴퓨터 빙고판 정의
void MakeBoard()
{
#ifdef DEV_LOG
	cout << "내 빙고판과 컴퓨터 빙고판 정의" << endl;
#endif
	// 수도코드
	// myBingo, comBingo를 for를 써서 1-25까지 초기화

	//내 빙고판 초기화
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		myBingo[i] = i + 1;
	}

	//컴퓨터 빙고판 초기화
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		comBingo[i] = i + 1;
	}

#ifdef DEV_LOG
	cout << "내 빙고판 값 : " << endl;
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		cout << myBingo[i] << endl;
	}

	cout << "컴퓨터 빙고판 값 : " << endl;
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		cout << comBingo[i] << endl;
	}
#endif
}

//2. 빙고판 셔플. (나, 컴퓨터)
void ShuffleBoard()
{
#ifdef DEV_LOG
	cout << "빙고판 셔플. (나, 컴퓨터)" << endl;
#endif

	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % BINGO_ARRAY_SIZE;
		int index2 = rand() % BINGO_ARRAY_SIZE;

		int temp = myBingo[index1];
		myBingo[index1] = myBingo[index2];
		myBingo[index2] = temp;
	}

	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % BINGO_ARRAY_SIZE;
		int index2 = rand() % BINGO_ARRAY_SIZE;

		int temp = comBingo[index1];
		comBingo[index1] = comBingo[index2];
		comBingo[index2] = temp;
	}

#ifdef DEV_LOG
	cout << "내 빙고판 값 : " << endl;
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		cout << myBingo[i] << endl;
	}

	cout << "컴퓨터 빙고판 값 : " << endl;
	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		cout << comBingo[i] << endl;
	}
#endif
}

//3. 빙고판을 출력 (나, 컴퓨터)
void PrintBoard()
{
#ifdef DEV_LOG
	cout << "빙고판을 출력 (나, 컴퓨터)" << endl;
#endif

	//5X5 형태로 찍는걸 원함
	// 1    5    3    2   11
	// 12   15   20   4   22

	cout << "내 빙고판 " << endl;
	for(int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			//[i,j] 
			// i => 세로줄
			// j => 가로줄
			// 세로줄인덱스 * 가로길이 + 가로줄인덱스

			if (myBingo[i * BINGO_SIZE + j] == -1)
			{
				cout << "XX\t";
			}
			else
			{
				cout << myBingo[i * BINGO_SIZE + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "상대 빙고판 " << endl;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[i * BINGO_SIZE + j] == -1)
			{
				cout << "XX\t";
			}
			else
			{
				cout << comBingo[i * BINGO_SIZE + j] << "\t";
			}
		}
		cout << endl;
	}
}

// 4. 내가 숫자를 하나 부른다.
void CallBingoNumber()
{
#ifdef DEV_LOG
	cout << "내가 숫자를 하나 부른다." << endl;
#endif

	cout << "[" << turn << "] 번째 턴!" << endl;

	bool isValidation = false;
	while (isValidation == false)
	{
		if (turn % 2 == 1)
		{
			cout << "빙고 숫자를 입력해주세요." << endl;

			int input;
			cin >> input;

			calledNumber = input;
		}
		else
		{
			// 상대가 숫자부르는 로직 수도코드
			// 일단 간단하게 1~25중에 랜덤으로 부르게.
			calledNumber = rand() % BINGO_ARRAY_SIZE + 1;
		}


		// 내 빙고판에 CalledNumber가 있으면 유효성 검증된 값.
		for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
		{
			if (myBingo[i] == calledNumber)
			{
				isValidation = true;
			}
		}
	}

	cout << "불린 숫자 : " << calledNumber << endl;
}

// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
void MarkBingoNumber()
{
	cout << "그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다." << endl;

	// 수도코드
	// 내 빙고판에서 calledNumber가 있는지 체크
	// 있으면 -1로 수정

	// 내빙고판에서 calledNumber가 있는지 없는지 체크는 하나씩 비교하면 됩니다.

	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		if (myBingo[i] == calledNumber)
		{
			myBingo[i] = -1;
		}
	}

	for (int i = 0; i < BINGO_ARRAY_SIZE; i++)
	{
		if (comBingo[i] == calledNumber)
		{
			comBingo[i] = -1;
		}
	}
}

// 6. 턴 변경
void GoToNextTurn()
{
	cout << "턴 변경" << endl;
	turn++;
}


void CheckBingoCount()
{
#ifdef DEV_LOG
	cout << "빙고갯수 체크" << endl;
#endif

	// 가로줄체크
	// 세로줄체크
	// 대각선 / 방향
	// 대각선 \ 방향
	myBingoCount = 0;

	// 내 빙고판 체크
	// -1이 마크된것.
	// 가로줄을 쭉 체크했을떄, -1인지.

	//가로줄체크
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (myBingo[i * BINGO_SIZE + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingoCount++;
		}

	}

	//세로줄체크
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (myBingo[j * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (myBingo[(BINGO_SIZE - 1) * i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingoCount++;
		}

		/*if (myBingo[4] == -1 &&
			myBingo[8] == -1 &&
			myBingo[12] == -1 &&
			myBingo[16] == -1 &&
			myBingo[20] == -1)
		{
			myBingoCount++;
		}*/
	}


	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (myBingo[i * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingoCount++;
		}
	}

#ifdef DEV_LOG
	cout << "내 빙고카운트 : " << myBingoCount << endl;
#endif



	comBingoCount = 0;

	// 내 빙고판 체크
	// -1이 마크된것.
	// 가로줄을 쭉 체크했을떄, -1인지.

	//가로줄체크
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[i * BINGO_SIZE + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			comBingoCount++;
		}

	}

	//세로줄체크
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < BINGO_SIZE; j++)
		{
			if (comBingo[j * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			comBingoCount++;
		}
	}

	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (comBingo[(BINGO_SIZE - 1) * i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			comBingoCount++;
		}

		/*if (myBingo[4] == -1 &&
			myBingo[8] == -1 &&
			myBingo[12] == -1 &&
			myBingo[16] == -1 &&
			myBingo[20] == -1)
		{
			myBingoCount++;
		}*/
	}


	{
		bool isBingoLine = true;
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			if (comBingo[i * BINGO_SIZE + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			comBingoCount++;
		}
	}

#ifdef DEV_LOG
	cout << "컴퓨터 빙고카운트 : " << comBingoCount << endl;
#endif

}