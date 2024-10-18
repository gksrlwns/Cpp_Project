#pragma once
//클래스 전방선언
class Day17Player;
class Day17Box;
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hWnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc;		// 유저에게 보여줄 화면

private: // 더블버퍼링 변수
	HDC _hdcBack = {};		// backbuffer, 유저에게 보이지 않는 화면
	RECT _rect = {};		// 화면 크기
	HBITMAP _bmpBack = {};	// 화면에 그릴 물감

private:
	//Day17Player _player;	// 문제가 생긴이유는
							// 그래, Day17Player 이런 클래스가 있다는건 이제 알겠는데,
							// Day17Player 가 무엇인지 알아야 객체를 만들수 있는데, 지금 뭔지몰라.

	Day17Player* _player;	// 이렇게하면 문제가 안생겨요.
							// 포인터는 뭐죠? 메모리 주소
							// 결과적으로 포인터는 4바이트짜리 정수값
	Day17Box* _box;
};

