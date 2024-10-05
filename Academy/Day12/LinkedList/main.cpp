#include <iostream>
#include "LinkedList.h"

class Time
{
public:
	int Day;
	int Hour;
	int Minute;
	int Second;
	int Milisecond;

public:
	Time operator+(Time otherTime)
	{
		Time newTime = {};
		newTime.Milisecond = this->Milisecond + otherTime.Milisecond;
		if (1000 <= newTime.Milisecond)
		{
			int addSecond = newTime.Milisecond / 1000;
			newTime.Second += addSecond;
			newTime.Milisecond %= 1000;
		}

		newTime.Second = this->Second + otherTime.Second;
		if (60 <= newTime.Second)
		{
			int addMinute = newTime.Second / 60;
			newTime.Minute += addMinute;
			newTime.Second %= 60;
		}

		newTime.Minute = this->Minute + otherTime.Minute;
		if (60 <= newTime.Minute)
		{
			int addHour = newTime.Minute / 60;
			newTime.Hour += addHour;
			newTime.Minute %= 60;
		}

		newTime.Hour = this->Hour + otherTime.Hour;
		if (24 <= newTime.Hour)
		{
			int addDay = newTime.Hour / 24;
			newTime.Day += addDay;
			newTime.Hour %= 24;
		}


		return newTime;
	}

};

using namespace std;

void main()
{
	// Linked List

	LinkedList<int> linkedList;

	for (int i = 0; i < 10; i++)
	{
		linkedList.AddData(i);
	}

	linkedList.RemoveData(5);
	linkedList.RemoveData(9);

	for (int i = 0; i < 8; i++)
	{
		cout << linkedList[i] << endl;
	}

	cout << "완료" << endl;

	// 클래스끼리 더하기 빼기 구현가능

	Time a = { 0,1,2,3 };
	Time b = { 1,2,3,4 };
	Time c = a + b;



}