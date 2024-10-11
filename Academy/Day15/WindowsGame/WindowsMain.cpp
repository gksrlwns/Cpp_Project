#include "pch.h"


//전역변수:
HINSTANCE	_hInstance;
HWND		_hWnd;

ATOM		MyRegisterClass(HINSTANCE hInstance);
BOOL		InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT		WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);
void		SetWindowSize(int x, int y, int width, int height);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// 1. 윈도우클래스를 등록
	MyRegisterClass(hInstance);

	// 2. 윈도우를 생성
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 3. 윈도우 메세지 루프
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = _T("GameClient");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return ::RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;

	HWND hWnd = CreateWindowW(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	SetWindowSize(WIN_START_X, WIN_START_Y, WIN_SIZE_X, WIN_SIZE_Y);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	::AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_hWnd, nullptr, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER);
}

POINT mousePos = {};

RECT rc1;
RECT rc2;
RECT player;

// 숙제 1. 
//  - 플레이어의 RECT가 상하좌우 최대로 움직였을때, 그걸 감싸고있는 RECT를 벗어나려고하면 
//    같이 움직인다.

// 숙제 2.
//  - 큰네모랑 플레이어랑 같이 움직이다가 다른 큰네모랑 충돌하게되면
//    플레이어의 RECT가 다른 큰 네모의 가운데로 순간이동한다.

// 숙제 3.
//  - 다른 솔루션으로 진행하셔도되고, (숙제1,과 2랑은 같은화면에 하기힘들거같아요)
//  - 게임모드를 정해서 1번키 누르면 숙제 1,2 씬
//                    2번키 누르면 숙제 3번 씬



LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		// 윈도우가 생성되었을때 발생하는 이벤트
		// 여기에서 초기화 동작
		srand(time(NULL));

		rc1 = { 100, 100, 600,  600 };

		rc2 = { 900, 100, 1200,  400 };

		player = { 200, 200, 250, 250 };

		SetTimer(hWnd, 1, 1000 / 60, NULL);
		break;
		
	case WM_LBUTTONDOWN:
		break;
	case WM_PAINT:
		{
			// 화면을 그리는 이벤트
			// 시작했을떄 호출한번되고, InvalidateRect라는 함수가 호출됐을때 한번 실행되고

			PAINTSTRUCT ps;
			HDC hdc = ::BeginPaint(hWnd, &ps);

			//Draw::Rectangle(hdc, rc1);
			Draw::Rectangle(hdc, rc2);
			Draw::Rectangle(hdc, player);

			::EndPaint(hWnd, &ps);
		}
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			player.top -= 1;
			player.bottom -= 1;
			break;
		case VK_RIGHT:
			player.left += 1;
			player.right += 1;
			break;
		case VK_LEFT:
			player.left -= 1;
			player.right -= 1;
			break;
		case VK_DOWN:
			player.top += 1;
			player.bottom += 1;
			break;
		default:
			break;
		}

		break;

	case WM_MOUSEMOVE:
	{
		mousePos.x = GET_X_LPARAM(lParam);
		mousePos.y = GET_Y_LPARAM(lParam);
	}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			InvalidateRect(hWnd, NULL, true);
			break;

		default:
			break;
		}
		break;

	case WM_DESTROY:
		// 윈도우 종료 메세지가 왔을때 발생되는 이벤트
		::KillTimer(hWnd, 1);
		::PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}