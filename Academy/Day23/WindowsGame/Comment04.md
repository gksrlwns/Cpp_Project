## 공지사항

```
숙제를 내면 제가 git을받아서 항상 숙제피드백을 드렸잖아요.

Windows API 부터는 숙제피드백이 힘듭니다.

원하시는 분있으면 따로 말씀해주시면 해드리는데,
모두 대상으로는 힘들어요.

원하는 부분이나, 특정로직이 어떻게해야할지 모르겠다.
여기서 더 최선이 있었을까
```

---

## 숙제풀이
### 숙제내용
```
1번 ~ 9번키를 누르면
각각 화면중앙에
1단나오게
2단나오게
등등으로 바꾸고

0번키를 누르면
1단~9단까지 다나오도록
```

### 수도코드 
#### 키인풋
 1. 0~9까지 입력하는것을 currentInput 으로 저장

#### Render
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

---
### 숙제 - 두더지잡기
```
두더지 9마리가 1초에 랜덤으로 하나씩 땅속에서 나오게됩니다.
그 두더지는 5초후에 다시 들어갑니다 
그리고 튀어나와있을때 두더지를 클릭하거나 A키를 누르면 (둘중에 원하는거 하나로해도 오케이)
점수가 1점 오릅니다.

게임은 끝나지않아요.
```
