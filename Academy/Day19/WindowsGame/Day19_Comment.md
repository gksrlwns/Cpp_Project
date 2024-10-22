# Day 19

## 리소스 매니저
---
### 리소스란?
```
 리소스 : 게임에 사용하는 에셋

 예를들면
 Texture, 
 Sprite, 
 Animation(Flipbook), 
 Sound
```

 - 첫번째로 구현할 내용
    - 이미지 출력

```
 Texture란?
  - 텍스처는 이미지파일 그자체
   (어떤 이미지를 로딩했고, 그 이미지에 대한 정보)
   (이미지를 담을 변수)
   ( + 투명색 )
   (WindowsAPI에서는 .bmp 확장자 파일만 그릴수있습니다.)


 Sprite란?
  - 스프라이트는 텍스처의 일부
   (여기부터 여기까지 잘라서 이만큼만 사용하겠다.)
   (텍스처 정보랑, x, y , width, height)

```


## extern
 - extern 키워드는 다른 파일에서도 쓸수있는 전역변수 선언
``` cpp
//pch.h
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
```