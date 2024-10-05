#include <iostream>
#include "Vector.h"
using namespace std;

void main()
{
	Vector<int> a;

	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}

	// 0.3이라는 애를 찾고싶어요.
	for (int i = 0; i < a.Size(); i++)
	{
		if (a[i] == 3)
		{
			cout << "찾았다" << endl;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		a.pop_back();
	}

	cout << "---------------" << endl;
	for (int i = 0; i < a.Size(); i++)
	{
		cout << a[i] << endl;
	}
}