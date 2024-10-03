#include <iostream>
using namespace std;

void main()
{
	// 프로그램을 만들때, 
	// 혹은 일부 로직을 만들때

	// 웬만하면 수도코드를 적어주세요.

	// 노트에 적는게 베스트고
	// 내가 노트를 안들고다닌다.
	// (노트가 너무싫다 하시는분들은) 주석으로 해주세요.

	// 저 회사생활할때는 노트하나사서 2주에 하나씩썻어요.

	// 주석으로는 못적는 내용. (화살표)

	// 계산기
	// 숫자1을 입력해주세요. [50]
	// 숫자2를 입력해주세요 [30]
	// 어떤 연산을 진행할까요? ( 1 : +, 2 : -, 3 : *, 4: / )  [1]
	// 결과 : 80

	int num1 = 0, num2 = 0, choice = 0;
	int result = 0;

	//printf("숫자1을 입력해주세요 : \n");
	//scanf_s("%d", &num1);
	//printf("숫자2를 입력해주세요 : \n");
	//scanf_s("%d", &num2);
	//printf("어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4: / ) \n");
	//scanf_s("%d", &choice);
	//printf("결과 : %d\n", result);


	//수도코드
	// 출력 : "숫자1을 입력해주세요"
	// 입력 : num1 변수
	// 출력 : "숫자2를 입력해주세요"
	// 입력 : num2 변수
	// 출력 : "어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4: / )"
	// 입력 : choice 변수
	// 
	// 만약 choice == 1 이면
	//		result = num1 + num2
	// 그렇지않고 만약 choice == 2 이면
	//		result = num1 - num2
	// 그렇지않고 만약 choice == 3 이면
	//		result = num1 * num2
	// 그렇지않고 만약 choice == 4 이면
	//		result = num1 / num2
	// 
	// 출력 : 결과 : result


	// 출력 : "숫자1을 입력해주세요"
	printf("숫자1을 입력해주세요");
	// 입력 : num1 변수
	scanf_s("%d", &num1);
	// 출력 : "숫자2를 입력해주세요"
	printf("숫자2를 입력해주세요");
	// 입력 : num2 변수
	scanf_s("%d", &num2);
	// 출력 : "어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4: / )"
	printf("어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4: / )");
	// 입력 : choice 변수
	scanf_s("%d", &choice);

	// 만약 choice == 1 이면
	if (choice == 1)
	{
		//		result = num1 + num2
		result = num1 + num2;
	}
	// 그렇지않고 만약 choice == 2 이면
	else if (choice == 2)
	{
		//		result = num1 - num2
		result = num1 - num2;
	}
	// 그렇지않고 만약 choice == 3 이면
	else if (choice == 3)
	{
		//		result = num1 * num2
		result = num1 * num2;
	}
	// 그렇지않고 만약 choice == 4 이면
	else if (choice == 4)
	{
		//		result = num1 / num2
		result = num1 / num2;
	}

	// 출력 : 결과 : result
	printf("결과 : %d\n", result);
}