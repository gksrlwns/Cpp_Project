#pragma once

//콘솔 꾸미기에 도움을주는 클래스

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,		//100
	GREEN = FOREGROUND_GREEN,	//010
	BLUE = FOREGROUND_BLUE,		//001
	YELLOW = RED | GREEN,
	PURPLE = RED | BLUE,
	CYAN = GREEN | BLUE,
	WHITE = RED | GREEN | BLUE
};

class ConsoleHelper
{
public:
	static void SetCursorPosition(int32 x, int32 y);
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};

