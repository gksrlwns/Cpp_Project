#include "pch.h"


//전역변수:
HINSTANCE	_hInstance;
HWND		_hWnd;

ATOM		MyRegisterClass(HINSTANCE hInstance);
BOOL		InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT		WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

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

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

int ellipseX = 100;
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		// 윈도우가 생성되었을때 발생하는 이벤트
		// 여기에서 초기화 동작
		ellipseX = 100;
		break;
		
	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case VK_NUMPAD1:
			printf("1번키를 눌렀다.\n");
			ellipseX = 300;
			::InvalidateRect(hWnd, nullptr, true);
			break;

		case '2':
		case VK_NUMPAD2:
			printf("2번키를 눌렀다.\n");
			ellipseX = 500;
			::InvalidateRect(hWnd, nullptr, true);
			break;

		default:
			break;
		}
		break;

	case WM_PAINT:
		{
			// 화면을 그리는 이벤트
			// 시작했을떄 호출한번되고, InvalidateRect라는 함수가 호출됐을때 한번 실행되고

			PAINTSTRUCT ps;
			HDC hdc = ::BeginPaint(hWnd, &ps);

			//for (int i = 0; i < 9; i++)
			//{
			//	wchar_t str[100];
			//	wsprintf(str, L"안녕하세요 %d", i);
			//	::TextOut(hdc, 100, 100 + 50 * i, str, lstrlenW(str));

			//	wstring str1 = format(L"안녕하세요{}", i);
			//	::TextOut(hdc, 100, 100 + 50 * i, str1.c_str(), str1.length());

			//	//구구단찍기를 실습할건데
			//	//1단       2단      3단
			//	//4단       5단      6단
			//	//7단       8단      9단
			//	// 이렇게 찍도록 실습하시면됩니다
			//	// 쉬는시간포함해서 9시 10분까지 드릴게요
			//}

			for (int i = 1; i <= 9; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					wstring str = format(L"{} x {} = {}", i, j, i * j);
					int x = 100 + ((i - 1) % 3) * 200;
					int y = 20 + ((i - 1) / 3) * 250;

					y += j * 20;
					::TextOut(hdc, x, y, str.c_str(), str.length());
				}
			}
			
			Draw::Rectangle(hdc, 10, 10, 100, 100);
			Draw::Ellipse(hdc, ellipseX, 500, 600, 600);

			::EndPaint(hWnd, &ps);
		}
		break;

	case WM_DESTROY:
		// 윈도우 종료 메세지가 왔을때 발생되는 이벤트
		::PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}