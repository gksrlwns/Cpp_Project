#include <iostream>

using namespace std;


void main()
{
	// 2. 숙제풀이 - 별찍기
	/*1번
	*
	**
	***
	****
	*****

	2번
	*****
	****
	***
	**
	*

	 3번
		 *
		**
	   ***
	  ****
	 *****

	 4번
	 *****
	  ****
	   ***
		**
		 *

	 5번
	 *    *****
	 **   ****
	 ***  ***
	 **** **
	 ******
		 ******
		** ****
	   ***  ***
	  ****   **
	 *****    **/

	//*
	//**
	//***
	//****
	//*****

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "[" << i << " " << j << "] ";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << endl << endl;
	//*****
	//****
	//***
	//**
	//*
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j <= 4)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}


	cout << endl << endl;
	//     *
	//    **
	//   ***
	//  ****
	// *****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= 4 - j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	// *****
	//  ****
	//   ***
	//    **
	//     *
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl;

	// *    *****
	// **   ****
	// ***  ***
	// **** **
	// ******
	//     ******
	//    ** ****
	//   ***  ***
	//  ****   **
	// *****    *

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 0; j < 5; j++)
		{
			if (i + j <= 4)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= 4 - j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}


//오늘 숫자야구 못하신분
//  제가 짠 숫자야구
//  타임어택 15분 주면 안보고 칠수있을정도로 외우세요.
// 주석제외.
