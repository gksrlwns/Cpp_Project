#include <iostream>

using namespace std;
enum class ERockScissorPaper
{
	Scissor,
	Rock,
	Paper,
	End
};
void main()
{
	// 숙제 못하신분들
	//  -> 안한거랑 못한거
	//  -> 못한분
	//  -> 하고싶은데, 어려워서 못했다
	//  -> 어떻게 건들여야할지 모르겠어서 못했다.

	//수도코드 작성해주세요.
	// 지금단계에서는 내가 하고싶은 말을 코드로 변환하는 능력까지는
	// 없어도 무방합니다.

	// 회사가서도 내 주류 언어가아니라 비주류언어도 시키거든요
	// 수도코드를 작성할줄만알면
	// 구글에 물어물어 가면서 다할수있어요.

	// 그냥 하고싶은데
	// 코드를 여기까지해봤는데 모르겠어요 << 
	// 어디서막혔는지 제가 추리를

	// 프로그래밍 수업은 에피소드 형식이 아닙니다.
	// 한번 놓치면 못따라가요
	// 새로운 로직배우고있는데
	// 어 저거는 무슨뜻이지 
	
	// 가위바위보 하나빼기 풀이

	// 수도코드
	
	// int arr[10]
	// arr[1] ~ arr[10] (x)
	// arr[0] ~ arr[9] (o)
	
	// 내가 낼것 2개를 정한다.
	// hand[2]  -> hand[0], hand[1]
	// 컴퓨터가 낼것 2개를 정한다.
	// comHand[2]

	// 내가 낸것 2개를 출력한다.
	// 컴퓨터가 낸것 2개를 출력한다

	// 그다음 내가 왼손을 낼건지 오른손을 낼건지 결정한다.
	
	// 컴퓨터도 랜덤으로 왼손과 오른손중에 결정한다.

	// 최종적으로 낸손을 서로 비교하여 승패판정을 내린다.


	// 내가 낼것 2개를 정한다.
	// 2개를 정하면 -> 정한 내용을 기억
	// 변수를 선언해서 기억
	// 2개이기 떄문에 배열을 활용하는게 좋다.
	// 정해야하니까, 어떻게 입력해야하는지 안내문구와 입력을 받아야겠죠
	int hand[2] = {};
	cout << "가위(0), 바위(1), 보(2) 중에 낼것을 두개 골라주세요." << endl;
	for (int i = 0; i < 2; i++)
	{
		cin >> hand[i];
	}

	// 컴퓨터가 낼것 2개를 정한다.
	int comHand[2] = {};
	// 컴퓨터가 내는건 입력받는게아니라 랜덤으로 뽑히면됩니다.
	srand(time(NULL));

	for (int i = 0; i < 2; i++)
	{
		comHand[i] = rand() % 3;
	}
	

	// 내가 낸것 2개를 출력한다.
	// 컴퓨터가 낸것 2개를 출력한다
	cout << "내가 낸것 : ";
	for (int i = 0; i < 2; i++)
	{
		if (hand[i] == (int)ERockScissorPaper::Rock)
		{
			cout << "바위 ";
		}
		else if (hand[i] == (int)ERockScissorPaper::Scissor)
		{
			cout << "가위 ";
		}
		else
		{
			cout << "보 ";
		}
	}
	cout << endl;

	cout << "컴퓨터가 낸것 : ";
	for (int i = 0; i < 2; i++)
	{
		if (comHand[i] == (int)ERockScissorPaper::Rock)
		{
			cout << "바위 ";
		}
		else if (comHand[i] == (int)ERockScissorPaper::Scissor)
		{
			cout << "가위 ";
		}
		else
		{
			cout << "보 ";
		}
	}
	cout << endl;


	// 그다음 내가 왼손을 낼건지 오른손을 낼건지 결정한다.
	
	cout << "왼손(0)과 오른손(1) 중에 골라주세요." << endl;
	int handChoice;
	cin >> handChoice;

	//finalHand[0] => 내가 최종적으로 낼것
	//finalHand[1] => 컴퓨터가 최종적으로 낼것
	int finalHand[2] = {};
	finalHand[0] = hand[handChoice];
	// 컴퓨터도 랜덤으로 왼손과 오른손중에 결정한다.
	finalHand[1] = comHand[rand() % 2];

	// 최종적으로 낸손을 출력한다.
	cout << "최종적으로 낸것" << endl;
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			cout << "플레이어 : ";
		}
		else if (i == 1)
		{
			cout << "컴퓨터 : ";
		}

		if (finalHand[i] == (int)ERockScissorPaper::Rock)
		{
			cout << "바위" << endl;
		}
		else if (finalHand[i] == (int)ERockScissorPaper::Scissor)
		{
			cout << "가위" << endl;
		}
		else
		{
			cout << "보" << endl;
		}
	}


	// 최종적으로 낸손을 승패판정을 내린다.
	if (finalHand[0] == finalHand[1])
	{
		cout << "비겼습니다." << endl;
	}
	else if (finalHand[0] == (int)ERockScissorPaper::Scissor && 
		finalHand[1] == (int)ERockScissorPaper::Rock)
	{
		cout << "패배했습니다." << endl;
	}
	else if (finalHand[0] == (int)ERockScissorPaper::Rock && 
		finalHand[1] == (int)ERockScissorPaper::Paper)
	{
		cout << "패배했습니다." << endl;
	}
	else if (finalHand[0] == (int)ERockScissorPaper::Paper && 
		finalHand[1] == (int)ERockScissorPaper::Scissor)
	{
		cout << "패배했습니다." << endl;
	}
	else
	{
		cout << "승리했습니다." << endl;
	}

}



 //컴공과 나오신 학생분들
 //위에거는 4줄
 //한줄로 적었으니, 더좋은거아닌가요?
 //왜 한줄로 적는게 더안좋은지
 //프로그램을 다 만들면 유지보수
 // -> 저런 포문하나짜리에 로그라도 들어갈 가능성이 되게 높아요.

 //프로그램을 다 만들면 유지보수
 // -> 한줄안에 로그를 적으면
 // -> 옆으로 길어져요.
 // -> 그냥 내리면되잖아요


 //프로그램을 더 적은 줄수로 해가지고 얻는 이득
 // -> 주요로직이 한눈에 보이기 때문에 가독성이 증가
 //-> 옆으로 적으면 
 //-> 옆으로 드래그해야하고 , 보편적인 형태도아니고 오히려 가독성을 깨쳐요.

 //변수명을 잘지을필요가 1도없거든요

 //좋은 프로그래밍
 // 1. 가독성
 // 2. 퍼포먼스
 // 3. 유지보수성
 // 4. 생산성
