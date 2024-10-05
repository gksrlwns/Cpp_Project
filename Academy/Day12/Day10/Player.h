#pragma once
class Player
{
public:
	int _card[2] = {};
	int _gold;

public:
	int GetJokboValue();
	void ShowInfo();
	void InitCard();
	void PrintJokbo();
};


