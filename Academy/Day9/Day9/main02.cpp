#include <iostream>
#include <Windows.h>
#define USER_COUNT 10
using namespace std;


void main()
{
	int a = 3;

	// 동적할당.
	//new int();
	// 4바이트 int형 메모리가 생성된거에요.
	// 그냥 RAM에 만들어진게 끝입니다.
	// new 자료형(); ==> 기본적으로 포인터가 전달됩니다.

	// 동적할당을 사용할때는 포인터와 같이 사용해요.
	int* myPointer = nullptr;
	myPointer = new int();
	// new int() => RAM에 4byte int형 메모리가 생성하였고
	// 그 주소를 myPointer가 인수받았다.

	// 1. 동적할당 하는방법
	//  - new 자료형();
	//  - 주솟값이 나오기때문에 항상 포인터로 받아줘야한다.
	//  - int* myPointer = new int();
	// 
	// 2. 동적할당 삭제하는 방법
	//  - delete 주솟값
	//  - 주솟값을 담은 포인터는 더이상 쓸모가 없으니 항상 nullptr로 초기화해준다.

	delete myPointer;
	myPointer = nullptr;


	// 메모리공간 4개
	// 힙 
	//	 - 생성과 삭제를 프로그래머가 제어할수 있습니다.
	
	// 스택 - 지역변수
	//   - 프로그래머가 삭제에 관여할수없습니다.
	//   - 중괄호 끝나면 알아서 삭제가 됩니다.



	// 그러면 아니 우리한테는 크게 쓸모없는 내용같은데?
	// 언제 생성과 삭제를 제어해야할지도 모르겠고, 왜해야하는지도 모르겠습니다.

	// 하나가 더있어요.
	// 배열.

	// 동적배열
	// 프로그램이 실행되는 도중에, 배열크기를 지정해서 선언하는 방법.


	int userCount = 4;
	// USER_COUNT = 3;

	int arr[USER_COUNT];	// 정적 배열


	// 동적배열
	// 사용하는방법
	// 포인터 = 배열
	
	int* arr = new int[userCount];
	arr[0] = 3;
	arr[9] = 10;

	// 동적배열 삭제하는 방법
	delete[] arr;
	
	
	// 동적할당 주의점
	// 항상 new를 했으면, delete를 해줘야합니다.

	// 만약에 delete를 안하면
	// 평생 메모리가 쌓여요 ( 메모리 누수 )
}