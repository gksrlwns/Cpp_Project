#include <iostream>
#include "MainGame.h"

using namespace std;

void main()
{
	// 1. 숙제풀이 - 섯다

	// 섯다
	// 
	// 룰 세팅
	// 1. 두명의 플레이어가 화투카드 1장씩 나눠갖는다.
	// 2. 두명의 플레이어가 서로 베팅한다.
	// 3. 한장씩 더 나눠갖는다. 
	// 4. 두명의 플레이어가 서로 베팅한다.
	// 5. 족보가 높은사람이 판돈을 모두 가져간다.

	// 수도코드
	// - 1. 화투카드 24장을 정의한다
	// - 2. 화투카드를 섞는다.
	// - 3. 두플레이어한테 한장씩 나눠준다.
	// - 4. 두플레이어가 각각 베팅한다.
	// - 5. 두플레이어한테 한장씩 나눠준다.
	// - 6. 두플레이어가 각각 베팅한다.
	// - 7. 족보가 높은사람한테 판돈을 모두 준다.

	MainGame* mainGame = new MainGame();
	mainGame->Init();

	mainGame->Run();

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}


// .h 
// .cpp 
// 의 차이점

// .cpp 파일은 코드가 컴파일되는 곳
//  실제로 코드 동작하는 곳

// .h 파일은 
//    cpp에서 동작해야하는 내용들을 (선언들)
//    줄여서 파일을 분리해둔곳

// #pragma once // << 이 전처리기를 적으면, 한번만 include가 됩니다. 
// #pragma once 이게 예전의 C++부터 있는 명령어가 아니었어요.

// 원래 사용하던 방식
// 간단하게 알려드리고, 넘어갈게요.
// #ifndef 활용