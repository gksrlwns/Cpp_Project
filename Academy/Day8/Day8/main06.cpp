#include <iostream>
#include <Windows.h>
using namespace std;

void UpdateGame();
void main()
{
	//현재 시간을 기억한다
	int oldGameTime = ::GetTickCount64();
	// GetTickCount64 게임이 진행되고 몇ms가 지났는가?

	while (true)
	{
		//현재 게임시간을 받아온다.
		int currentGameTime = ::GetTickCount64();

		//현재시간 - 옛날시간
		if (300 < currentGameTime - oldGameTime)
		{
			UpdateGame();
			oldGameTime = currentGameTime;
		}
	}
}

void UpdateGame()
{
	cout << "뱀이 움직일 시간" << endl;
}