#include <iostream>
#include "MainGame.h"
using namespace std;


void main()
{
	MainGame* mainGame = new MainGame();
	mainGame->Init();

	/*while (mainGame->IsGameEnd() == false)
	{
		mainGame->Update();
	}*/
	mainGame->Run();

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}