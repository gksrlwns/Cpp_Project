#include <iostream>

using namespace std;

void main()
{
	// 수도코드
	// [출력] 중간평가 점수를 입력해주세요.
	// [입력] middleScore
	// [출력] 기말평가 점수를 입력해주세요.
	// [입력] finalScore
	// [출력] 출석 점수를 입력해주세요.
	// [입력] attendanceScore
	// [출력] 과제 점수를 입력해주세요.
	// [입력] homeworkScore
	// [연산] totalScore = middleScore + finalScore + attendanceScore + homeworkScore
	// if( totalScore <= 60 ) 
	//	[출력] F
	// else if( totalScore <= 70 ) 
	//	[출력] D
	// else if( totalScore <= 80 ) 
	//	[출력] C
	// else if( totalScore <= 90 ) 
	//	[출력] B
	// else 
	//	[출력] A

	int middleScore = 0;
	int finalScore = 0;
	int attendanceScore = 0;
	int homeworkScore = 0;
	int totalScore = 0;
	printf("중간평가 점수를 입력해주세요.\n");
	scanf_s("%d", &middleScore);
	printf("기말평가 점수를 입력해주세요.\n");
	scanf_s("%d", &finalScore);
	printf("출석 점수를 입력해주세요.\n");
	scanf_s("%d", &attendanceScore);
	printf("과제 점수를 입력해주세요.\n");
	scanf_s("%d", &homeworkScore);

	totalScore = middleScore + finalScore + attendanceScore + homeworkScore;

	if (totalScore <= 60)
	{
		printf("F\n");
	}
	else if (totalScore <= 70)
	{
		printf("D\n");
	}
	else if (totalScore <= 80)
	{
		printf("C\n");
	}
	else if (totalScore <= 90)
	{
		printf("B\n");
	}
	else
	{
		printf("A\n");
	}
}


/*
 2. 학점 계산기
 // 출력예시
 //	 중간평가 점수를 입력해주세요.
 //	 기말평가 점수를 입력해주세요.
 //  출석점수를 입력해주세요.
 //  과제 점수를 입력해주세요.
 // F입니다. (0 ~ 60 F, ~ 70 D, ~ 80 C, ~ 90 B, ~ 100 A)
*/