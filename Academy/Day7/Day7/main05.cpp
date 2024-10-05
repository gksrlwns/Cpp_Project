#include <iostream>

using namespace std;


void Function1(int* a);
void Function2(int& b);
void Function3(int arr[], int arrSize);
void Function4(int* arr , int arrSize);
void main()
{
	//함수-2

	// 전방선언
	// 간단하게 사용하는 방법

	int value = 20;
	Function1(&value);

	//함수에서 일어나는일 재현
	/*{
		int* a = &value;
		{
			cout << "Function1" << endl;
			cout << "a : " << *a << endl;
			*a = 10;
		}
	}*/

	

	// 그렴 함수를 쓰면 값을 수정할수는 없나요?
	// 여러분들이 배운 지식으로
	// 가능은 합니다.
	// 포인터

	cout << "value : " << value << endl;

	// 2번째, 레퍼런스 형태를 사용해서 값을 바꾸는 방법
	// 이거를 조금더 추천드립니다.
	// 

	Function2(value);
	cout << "value : " << value << endl;
	// 돼지꼬리를 붙이면
	// 변수가 새로 생성되는게 아니라
	// 변수가 전이됩니다.
	// 영혼만 떠서 붙여주는거에요
	{
		int& b = value;
		{
			cout << "Function2" << endl;
			cout << "b : " << b << endl;
			b = 30;
		}
	}
	cout << "value : " << value << endl;


	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Function3(arr, 10);
	Function4(arr, 10);
}

void Function1(int* a)
{
	cout << "Function1" << endl;
	cout << "a : " << *a << endl;
	*a = 10;
}

void Function2(int& b)
{
	cout << "Function2" << endl;
	cout << "b : " << b << endl;
	b = 30;
}

void Function3(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << endl;
	}

}


void Function4(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << *(arr + i) << endl;
	}
}