# Windows API 1일차
---

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


### 숙제
```
1번 ~ 9번키를 누르면
각각 화면중앙에
1단나오게
2단나오게
등등으로 바꾸고

0번키를 누르면
1단~9단까지 다나오도록
```