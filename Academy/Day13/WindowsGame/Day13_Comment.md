# Day13
## Windwos API

### Windows API 란?

```
#include <Windows.h>
에 있는 함수를 사용하는게 Windows API 입니다.

API라는 명칭에 대해 조금 배워야하는데 
Application Programming Interface
어플리케이션 프로그래밍할때 쓰이는 함수 모음집

Andorid API 
 - 안드로이드 만들때 사용하는 함수모음집
```

### 그럼 굳이 Windows API를 배우는 이유
```
 게임엔진을 바로 배워서 게임을 만들수도있는데,
 게임엔진안에는 대부분의 기술이 구현되어있습니다.

 그래서 어떤 기술이 퍼포먼스 저하를 부르는지
 어떤 기술이 어떻게 작동하는지 알아야
 더 좋은 프로그래머가 될 수 있습니다.

 그래서 저희는 WindowsAPI를 할때,
 게임을 만들때 필요한 기본으로 제공되어야할만한 기능들
 (게임엔진에서 제공하는 기능들)
 을 구현할거에요.

 아무것도 안되어 있기 떄문에 배우는겁니다.
 그렇다고 콘솔로 계속하기에는 좀 없어보이고
 기술도 조금 많이 달라져요
 Console과 Graphic의 차이가 조금 있습니다.
```

### Windows API 초기화

#### 1. Main 문 정의
```cpp
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)

	- instance
	- prevInstance
	- lpCmdLine
	- nCmdShow

	instance - 실행되고있는 프로그램

	보통 앞에 H가붙으면 HANDLE이라고 생각해주세요.
```


#### Main문 내용
```cpp
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

	윈도우 어플리케이션을 실행시키기위해서는
	저 세가지를 꼭해야합니다.
	이거는 MS에서 지정한거에요.
	// 1. 윈도우클래스를 등록
	// 2. 윈도우를 생성
	// 3. 윈도우 메세지 루프
	 - 마우스를 움직이거나, 클릭을하거나
	 - 타이머를 설정했는데 타이머 시간이 됐거나,
	 - 이벤트들이 어떻게 작동할까에 대한 해석

	 - DispatchMessage를 실행시키게되면
	  실행하는 함수가 따로있음
	  (윈도우 프로시저)
```
#### 윈도우클래스 등록
```cpp
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
```
1. 윈도우클래스를 등록 
 - MS에서 지정한 함수이기때문에 MS 문서를 봐야합니다.
 [RegisterClassExW](https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-registerclassexw)

 - wcex.lpfnWndProc = WndProc;
	
#### 윈도우 생성
```cpp

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

// MS 가이드문서에서 CreateWindow 후에 
// ShowWindow, UpdateWindow 하라고 명시되었습니다.

// _hWnd - 실행되고있는 프로그램 그자체

 instance - 프로그램별로 존재합니다.
 window - 실행되는 프로그램별로 존재합니다.
```

#### 윈도우 프로시저
```cpp
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}
// 윈도우프로시저 - 현재 메세지를 어떻게 처리할지에 대한 함수
// HWND hWnd - 지금 실행되는 프로그램 (어디에 메세지가 온건지)
// UINT message - 어떤종류의 메세지가 왔는지 (마우스가 움직였는지, 마우스를 클릭했는지, 키보드를 눌렀는지)
// WPARAM wParam - 메세지설명1
// LPARAM lParam - 메세지설명2

로그를 찍을 때
- 어떤 뽑기를 했다. 메시지번호 25
- 사용자 직업 등등
wParam
lParam

마우스가 움직였다는 메세지가왔는데
마우스가 어디로 움직였는지 알방법이 없죠?
wParam - x좌표
lParam - y좌표

키보드를 눌렀다
wParam - 어떤 키를 눌렀는지
lParam - 사용안함.
```
#

## 1. 구구단 찍기
### 필요한 기능
 1. 글자 출력하는 방법
```cpp
 TextOut(HDC hdc,int x,int y,LPCWSTR lpString, int c)

 // hdc - Device Context ( 화면 구조체 )
 // x, y - 어떤위치에
 // lpString - 어떤글자를
 // c - 문자열길이

 // 콘솔에서 printf랑 같은 기능
 // 보통 개발할때 옆에 콘솔창 띄워두고 합니다.
 // printf는 콘솔창에써지고
 // TextOut은 화면에 그려집니다.

 //LPCWSTR - WCHAR* 형태
 //WCHAR - wchar_t
```

### WCHAR, CHAR 차이
```
 //wchar_t - 은 무엇일까
 //char, wchar

 char - 1byte
 wchar - 2byte

 한글은 2byte고
 영문은 1byte입니다.

 1byte는 크기가 256입니다.
 그러다보니 전세계문자를 다 표현할수가 없어요.

 1byte는 UTF-8 (ASCII) 이라고 하는 문자열 포맷을 사용합니다.
 UTF-8 - 국제적으로 ?bit를 사용할때 65 는 0 32는 a 이렇게 표현하자
         라고 약속하는 문자열 규격
 UTF-16 - 국제적으로 16비트를 사용할때 사용하는 문자열 규격

 2바이트를 적었는데,
 어떤컴퓨터에서는 
 aa라고 인식하고
 어떤컴퓨터에서는
 ※ 이런 문자로 인식

 이거를 하나로 통일시켜줘야합니다.

 보통 해외국가까지 퍼블리싱을 생각하면
 UTF-16으로 작업하게됩니다.

 UTF-8 - char
 UTF-16 - wchar
 입니다.

 앞으로는 문자열을 편하게 다루기위해서
 string 클래스를 사용할건데

 string, char 랑 짝이고
 wstring, wchar 랑 짝입니다.

```

## 2. 사각형 그리기
### 필요한 기능
 1. 사각형/원을 그리는 방법
```cpp
  //사각형그리기
  Rectangle(hdc, left, top, right, bottom);
  //원그리기
  Ellipse(hdc, left, top, right, bottom);
  // left - 좌측 x좌표
  // top - 상단 y좌표
  // right - 우측 x좌표
  // bottom - 하단 y좌표

  // windows api의 좌표계는
  // 좌측상단이 0,0 입니다.

  // 사각형을 그리거나
  // 타원을 그릴때
  // x, y, width, height 이게좀더 좋을거같은데
  // 저희만의 함수로 따로 만들어줍니다.
  // WindowsAPI의 함수를 사용하기 편하게

  // 제공해준대로 안쓸떄가 더 많거든요
```


### namespace
```
namespace는 이름공간

using namespace std;
// std를 생략하고 함수를 작성하겠다
// std::format ==> format 

format이라는 함수를 A라이브러리 개발자도 만들수있고, 나도 만들수있다.

namespace std
{
    void format()
    {
    }
}

이 함수를 사용하기위해선
std::format 형태로 사용합니다.


```
