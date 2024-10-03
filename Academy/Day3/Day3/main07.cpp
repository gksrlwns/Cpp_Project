#include <iostream>

using namespace std;

void main()
{
	// 연산자
	// 남은시간동안 숙제할시간
	// 모르는거 있으신분들 좀 개인적으로 봐드리는시간

	// 연산자
	// 대입연산자, 비교연산자, 산술연산자, 논리연산자, 증감연산자, 비트연산자


	// 증감연산자
	int number1 = 7;

	//number1여기에 3을 더하고싶어요
	number1 = number1 + 3;
	number1 = number1 - 3;

	// 이게 똑같은걸 적는게 귀찮다
	// 나온 연산자가 증감연산자
	number1 = number1 + 3;
	number1 += 3;

	number1 *= 3;
	number1 -= 3;
	number1 /= 3;
	number1 %= 3;
	number1 += 3;

	// 더있어요.
	number1 += 1;
	number1 -= 1;

	number1++;	//1더하기
	number1--;	//1빼기
	++number1;	//1더하기
	--number1;	//1빼기

	int num1 = 0;
	printf("\n%d\n", num1++);

	int num2 = 0;
	printf("\n%d\n", ++num2);


	// 논리연산자
	// &&, || 
	// 수도코드를 말로 풀때 되게 중요한 역할을 합니다.
	// and -> &&
	// or -> ||

	// 값싸고(and) 질좋으면 산다.

	// 전철이나 버스를 탄다
	//     (or)

	// hp가 0보다 아래고 부활스킬을 가졌다면
	//		부활한다.

	// i 버튼을 눌렀거나, 인벤토리 버튼을 눌렀다면
	//		인벤토리창이 켜진다.


	float hp = -3;
	bool haveResurrection = true;

	if (hp <= 0 && haveResurrection)
	{
		printf("부활한다.\n");
	}

	if (hp <= 0)
	{
		if (haveResurrection)
		{
			printf("부활한다.\n");
		}
	}

	bool InputQKey = true;
	int mp = 100;
	if (InputQKey)
	{
		if (100 < mp)
		{
			printf("Q스킬을 발동한다.\n");
		}
	}

	//팁을 드리면
	//  && 연산은 앞에서부터 false가 나오면 그만둡니다.
	//  || 연산은 앞에서부터 true가 나오면 바로 중괄호 진입합니다.

	int zero = 0;

	if (false && (1 / zero) == 3)
	{
		printf("안들어오고 뻑도안남\n");
	}

	if (true || (1 / zero) == 3)
	{
		printf("들어오고 뻑도안남\n");
	}

	//int value = 1 / zero;


	// 가위바위보 팁을 드리면
	// 승패판정
	// hand => 0 가위 1 바위 2 보
	// comHand => 0 가위 1 바위 2 보

	// 수학적으로 잘해보면
	// hand - comHand 해서 뭐 되지않을까?
	// 이거 하지마세요.
	// 가독성 떨어집니다.
	// 좋은 코드가 나오지도 않습니다.
	// 게임 승패를 판정하는 로직은 
	// 정직하면 정직할수록 가독성이 올라갑니다.
}