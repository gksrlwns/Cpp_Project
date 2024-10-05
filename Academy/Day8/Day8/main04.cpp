#include <iostream>

using namespace std;
//실습
//
// 플레이어, 몬스터
// 각각의 스탯이존재합니다.
// 플레이어와 몬스터가 가위바위보를 합니다.
// 이긴쪽이 한대 때려요.
// 그래서 한쪽이 죽을떄까지 가위바위보를 합니다. (가위바위보가 어려우면 돌아가면서 한대씩 때리게끔.)
// 플레이어가 승리했는지, 패배했는지 문구띄워주는 게임을 실습
// 쉬는시간포함해서 30분드리겠습니다.

//1. 구조체 정의
struct Monster
{
	float hp;
	float attack;

	void PrintInfo(Monster otherMonster)
	{
		cout << "몬스터 HP : " << this->hp << endl;
		cout << "몬스터 ATK : " << this->attack << endl;

		cout << "다른 몬스터 HP : " << otherMonster.hp << endl;
		cout << "다른 몬스터 ATK : " << otherMonster.attack << endl;
	}
};
void main()
{
	//2. 구조체 초기화
	Monster monster = { };
	monster.hp = 10;
	monster.attack = 20;

	Monster monster2 = { };
	monster2.hp = 30;
	monster2.attack = 10;

	monster.PrintInfo(monster2);
}


// int, float, __int64, char, bool
// 기본자료형

// 사용자 정의 자료형


// 기본자료형
//  -> 언어에서 기본적으로 제공해주는 자료형
//     (정수, 실수, 문자열, 참거짓 등)

// 사용자 정의 자료형
//  -> 저희가 직접 자료형을 만드는거에요.
//     (enum, struct, class)
//  -> 말이 사용자 정의자료형이지
//     그냥 정수형 아니었나요?


//구조체는 
// 변수 + 함수들을 묶어놓는 기능