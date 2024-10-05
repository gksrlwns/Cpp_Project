#pragma once
#include "Player.h"
class MainGame
{
public:
	void Init();
	void Run();
	void Release();

public:
	//화투카드 정의
	void InitCard();
	//플레이어 초기화
	void InitPlayerData();
	//카드 섞기
	void ShuffleCard();
	//플레이어에게 한장씩 카드 나눠주기
	void HandOutCardsToPlayers();
	//플레이어 베팅
	void BetPlayer();
	//플레이어 게임결과 정산
	void ProceedWithGameResult();

public:
	int _card[20] = {};
	Player _player[2] = {};
	int _allBetMoney = 0; // 판돈
};



// 수도코드
// - 1. 화투카드 24장을 정의한다
// - 2. 화투카드를 섞는다.
// - 3. 두플레이어한테 한장씩 나눠준다.
// - 4. 두플레이어가 각각 베팅한다.
// - 5. 두플레이어한테 한장씩 나눠준다.
// - 6. 두플레이어가 각각 베팅한다.
// - 7. 족보가 높은사람한테 판돈을 모두 준다.