#include "MainGame.h"
#include <iostream>
using namespace std;

void MainGame::Init()
{
	srand(time(NULL));
	this->InitCard();
	this->InitPlayerData();
	this->ShuffleCard();
}
void MainGame::Run()
{
	while(0 < _player[0]._gold && 0 < _player[1]._gold)
	{
		HandOutCardsToPlayers();
		BetPlayer();
		HandOutCardsToPlayers();
		BetPlayer();
		ProceedWithGameResult();
	}
}

void MainGame::Release()
{

}


//화투카드 정의
void MainGame::InitCard()
{
	for (int i = 0; i < 20; i++)
	{
		_card[i] = i;
	}
}

//플레이어 초기화
void MainGame::InitPlayerData()
{
	for (int i = 0; i < 2; i++)
	{
		//카드 초기화
		for (int j = 0; j < 2; j++)
		{
			_player[i]._card[j] = -1;
			_player[i]._card[j] = -1;
		}

		//골드초기화
		_player[i]._gold = 10000;
	}
}

//카드 섞기
void MainGame::ShuffleCard()
{
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 20;
		int index2 = rand() % 20;

		int temp = _card[index1];
		_card[index1] = _card[index2];
		_card[index2] = temp;
	}
}

//플레이어에게 한장씩 카드 나눠주기
void MainGame::HandOutCardsToPlayers()
{
	//카드덱에서 한장씩 꺼내서 주면됩니다.
	
	//원래는 mainGame클래스안에 몇번째카드를 지금 줘야하는지 이런 변수를 넣어야하는데,
	// static이라는 키워드를 배우기위해 잠깐만 편법으로사용할게요.

	static int cardIndex = 0;

	for (int i = 0; i < 2; i++)
	{
		if (_player[i]._card[0] == -1)
		{
			_player[i]._card[0] = _card[cardIndex++ % 20];
		}
		else
		{
			_player[i]._card[1] = _card[cardIndex++ % 20];
		}
	}

#ifdef DEV_LOG
	cout << " cardIndex : " << cardIndex << endl;
#endif
}

//플레이어 베팅
void MainGame::BetPlayer()
{
	cout << "현재 판돈 : " << _allBetMoney << endl;
	int betMoney;
	// 1번플레이어 베팅시작
	_player[0].ShowInfo();
	cout << "얼마를 베팅하시겠습니까?" << endl;
	cout << "최소 (0원) ~ 최대 (" << _player[0]._gold << "원)" << endl;
	cin >> betMoney;

	while (false == (0 <= betMoney && betMoney <= _player[0]._gold))
	{
		cout << "다시 입력해주세요." << endl;
		cin >> betMoney;
	}
	_player[0]._gold -= betMoney;
	_allBetMoney += betMoney;

	// 2번플레이어 베팅시작
	_player[1]._gold -= betMoney;
	_allBetMoney += betMoney;
}

//플레이어 게임결과 정산
void MainGame::ProceedWithGameResult()
{
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << i + 1 << "번 플레이어 : " << endl;
		_player[i].PrintJokbo();
	}

	int player1Jokbo = _player[0].GetJokboValue();
	int player2Jokbo = _player[1].GetJokboValue();

	if (player1Jokbo < player2Jokbo)
	{ 
		cout << "2번 플레이어가 이겼습니다." << endl;
		_player[1]._gold += _allBetMoney;
		_allBetMoney = 0;
	}
	else if (player2Jokbo < player1Jokbo)
	{
		cout << "1번 플레이어가 이겼습니다." << endl;
		_player[0]._gold += _allBetMoney;
		_allBetMoney = 0;
	}
	else if (player2Jokbo == player1Jokbo)
	{
		cout << "비겼습니다." << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		_player[i].InitCard();
	}
}