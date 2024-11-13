#include "pch.h"
#include "Board.h"
#include "Player.h"
#include <assert.h>
void main()
{
	//보통 assert는 validation check할떄 많이 사용합니다. 
	// 개발용으로
	//assert(false);


	Board board;
	Player player;

	board.Init(&player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		if (500 < deltaTick)
		{
			lastTick = currentTick;
			player.Update();
			board.Render();
		}
	}
}