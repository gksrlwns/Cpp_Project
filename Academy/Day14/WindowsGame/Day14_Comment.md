# Day14
## 수도코드 
### 키인풋
 1. 0~9까지 입력하는것을 currentInput 으로 저장

### Render
```
if (1 <= currentInput and currentInput <= 9) then
	화면 중앙 currentInput단 출력
else
	1단 ~ 9단 출력
```


## 마우스 이동 감지 (위치감지)
```
WM_MOUSEMOVE 를 통해 마우스 이동감지를 합니다.
```

## 타이머
```
 타이머란
  - 타이머 호출 주기가 되면 WM_TIMER를 호출할수있게하는 기능

 사용방법
  - SetTimer(_hWnd, 타이머ID, 타이머 호출주기(ms), NULL);
  - KillTimer(_hWnd, 타이머ID)
  - WM_TIMER / wParam이 타이머ID로 오게됩니다.

게임이 주로 60프레임
```

### 프레임이란?
```
 FPS - Frame Per Seconds
 1초에 화면이 몇번 전환되느냐

 [현재 저희입장으로 따지면]
 1초에 InvalidateRect를 몇번 호출하느냐

 60fps -> 1초에 60번 화면이 전환된다.
 타이머에서 InvalidateRect를 호출시켜줄건데
 1000 / 60 ms 를 호출주기로 가지면 
 60fps를 유지할수있다.
```


## 충돌체크 **(게임에서 가장많이 쓰이는 기술)**
```
수학적인 내용

if ( rc.left <= mousePos.x and mousePos.x <= rc.right ) then
	if ( rc.top <= mousePos.y and mousePos.y <= rc.bottom) then
		충돌
```
실습
적군 9개를 그리고
적군를 클릭하면 그 네모를 지워주게끔

9개가 어려우신분들은 1개로 해주세요.
30분까지 드릴게요

```
수도코드

class Enemy
{
public:
	RECT rc;
	bool isLive;

	Die()
	Draw()
}

WM_CREATE:
 for(int i = 0; i < 9; i++)
	enemies.Add(new Enemy({각자 위치}));

WM_PAINT:
	for ( enemy in enemies ):
		if( enemy.IsLive() ) then
			enemy.Draw()

WM_KEYDOWN:
	for ( enemy in enemies ):
		if ( enemy.rc.left <= mousePos.x and mousePos.x <= enemy.rc.right ) then
			if ( enemy.rc.top <= mousePos.y and mousePos.y <= enemy.rc.bottom) then
				enemy.Die()

```