#include "Player.h"
#include <iostream>
using namespace std;


int Player::GetJokboValue()
{	

	int card1 = _card[0];
	int card2 = _card[1];

	if (card2 < card1)
	{
		int temp = card1;
		card1 = card2;
		card2 = temp;
	}

	if (card1 == 2 && card2 == 7)
	{
		return 100000;
	}
	else if (card1 == 0 && card2 == 7)
	{
		return 10000;
	}
	else if (card1 == 0 && card2 == 2)
	{
		return 9999;
	}
	else if (card1 % 10 == card2 % 10)
	{
		return (card1 % 10) * 100;
	}
	else
	{
		return ((_card[0] + 1) + (_card[1] + 1)) % 10;
	}
}

void Player::ShowInfo()
{
	cout << "[플레이어 정보]" << endl;
	cout << "플레이어 골드 : " << _gold << endl;
	cout << "플레이어 카드 : " << endl;

	for (int i = 0; i < 2; i++)
	{
		if (_card[i] == -1) continue;
		//삼항 연산자 : (조건식)? 참일때 하는 명령 : 거짓일때 하는 명령;
		//이프문을 짧게 줄이는 용도인데, 잘 안써요.

		(10 <= _card[i]) ? cout << "☆" : cout << "★";
		cout << _card[i] % 10 + 1;

		cout << "\t";
	}
	cout << endl;
}

void Player::PrintJokbo()
{
	for (int i = 0; i < 2; i++)
	{
		if (_card[i] == -1) continue;
		//삼항 연산자 : (조건식)? 참일때 하는 명령 : 거짓일때 하는 명령;
		//이프문을 짧게 줄이는 용도인데, 잘 안써요.

		(10 <= _card[i]) ? cout << "☆" : cout << "★";
		cout << _card[i] % 10 + 1;

		cout << "\t";
	}
	cout << endl;


	int card1 = _card[0];
	int card2 = _card[1];

	if (card2 < card1)
	{
		int temp = card1;
		card1 = card2;
		card2 = temp;
	}

	if (card1 == 2 && card2 == 7)
	{
		cout << "38광땡";
	}
	else if (card1 == 0 && card2 == 7)
	{
		cout << "18광땡";
	}
	else if (card1 == 0 && card2 == 2)
	{
		cout << "13광땡";
	}
	else if (card1 % 10 == card2 % 10)
	{
		cout << card1 + 1<< "땡";
	}
	else if (card1 % 10 == card2 % 10)
	{
		cout << card1 + 1 << "땡";
	}
	else
	{
		cout << ((_card[0] + 1) + (_card[1] + 1)) % 10 << "끗";
	}

	cout << endl;
}

void Player::InitCard()
{
	for (int i = 0; i < 2; i++)
	{
		_card[i] = -1;
	}
}