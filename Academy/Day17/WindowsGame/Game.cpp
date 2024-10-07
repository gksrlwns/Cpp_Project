#include "pch.h"
#include "Game.h"
#include "Day17Player.h"
#include "Day17Box.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(HWND hWnd)
{
	this->_hwnd = hWnd;

	//1. _hdc를 유저에게 보여줄 DC로 받아준다.
	this->_hdc = ::GetDC(_hwnd);


	//==========================================
	//	## 더블버퍼링 세팅 ##
	//==========================================
	
	//2. _hdc 화면과 똑같은 크기의 화면을 생성한다.
	_hdcBack = ::CreateCompatibleDC(_hdc);
	// 윈도우의 크기를 받아옴
	::GetClientRect(_hwnd, &_rect);
	// hdc와 호환되는 비트맵 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
	//_hdcBack에 _bmpBack 연결
	HBITMAP prev = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	// 기존에 적용되어있던 _hdcBack 비트맵 삭제
	DeleteObject(prev);


	Input->Init(_hwnd);
	Time->Init();


	_player = new Day17Player();
	_player->Init();

	_box = new Day17Box();
	_box->Init();


	_player->SetLinkBox(_box);
	// 2가지방법
	// 1. Player에서 Box를 가져와서 
	//    Box를 미는 방식

	// 2. Box에서 Player를 가져와서
	//    밀리는 방식
}

void Game::Update()
{
	Input->Update();
	Time->Update();


	_player->Update();
	_box->Update();
}

void Game::Render()
{
	//FPS 출력
	{
		uint32 fps = Time->GetFps();
		float deltaTime = Time->GetDeltaTime();

		wstring timeStr = ::format(L"FPS({}), DeltaTime({} ms)", fps, static_cast<int32>(deltaTime * 1000));
		Draw::Text(_hdcBack, 0, 0, timeStr);
	}

	_player->Render(_hdcBack);
	_box->Render(_hdcBack);



	//==========================================
	//	## 더블버퍼링 세팅 ##
	//==========================================

	// 1. hdcBack의 내용을  hdc로 복사한다.
	BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);

	// 2. hdcBack의 내용을 깨끗이 지운다.
	PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}