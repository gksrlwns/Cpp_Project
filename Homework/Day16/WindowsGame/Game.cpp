#include "pch.h"
#include "Game.h"
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


	_input.Init(_hwnd);


	_player = CenterRect(300, 100, 80, 80);
}

void Game::Update()
{
	_input.Update();

	if (_input.GetKey(KeyCode::Left))
	{
		_player.pos.x -= 0.5;
	}
	if (_input.GetKey(KeyCode::Up))
	{
		_player.pos.y -= 0.5;
	}
	if (_input.GetKey(KeyCode::Right))
	{
		_player.pos.x += 0.5;
	}
	if (_input.GetKey(KeyCode::Down))
	{
		_player.pos.y += 0.5;
	}
}

void Game::Render()
{
	_player.Draw(_hdcBack);

	//==========================================
	//	## 더블버퍼링 세팅 ##
	//==========================================
	
	// 1. hdcBack의 내용을  hdc로 복사한다.
	BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);

	// 2. hdcBack의 내용을 깨끗이 지운다.
	PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}