## 배울 내용
 1. 숙제풀이 
 2. C++ 형변환 종류 3가지
 3. 사각형과 사각형의 충돌체크

---


## 1. 숙제풀이 
---
```
두더지 9마리가 1초에 랜덤으로 하나씩 땅속에서 나오게됩니다.
그 두더지는 5초후에 다시 들어갑니다 
그리고 튀어나와있을때 두더지를 클릭하거나 A키를 누르면 (둘중에 원하는거 하나로해도 오케이)
점수가 1점 오릅니다.

게임은 끝나지않아요.
```

```cpp
// 두더지 잡기 수도코드

WM_CREATE:
	SetTimer(hWnd, 2, 1000, NULL);
	//1초에 하나씩 두더지가 튀어오르게 설정

WM_PAINT:
	//두더지그리기
	for (Enemy enmey in enemies):
		if(enmey.IsLive())
			enemy.Draw()

	//스코어 텍스트 그려주기
	DrawText(score)

//로직적인부분
WM_KEYDOWN:
WM_LBUTTONDOWN:
	// 마우스를 눌렀을때, 두더지가 살아있으면 두더지 죽이기
	for (Enemy enmey in enemies):
		//PtInRect -> Rect안에 Point가 있는지 (있으면 True, 없으면 False)
		if(PtInRect(mousePos, enemy.rc) and enemy.IsLive())
			enemy.Die()
			score++;
			// KillTimer(100 * enemy.number)

WM_TIMER:
	case 2:
	{
		//튀어나올 두더지 랜덤뽑기 (1 ~ 9)
		int enemyNumber = rand() % 9 + 1;
		// 5초후에 두더지가 알아서 죽게끔.
		SetTimer(hWnd, enemyNumber * 100, 5000, NULL);	
		enemies[enemyNumber - 1].Spawn();
	}
	break;

	case 100:
		enemies[0].Die();
	break;

```


## 2. C++ 형변환 종류 3가지
--- 
1. static_cast
 - 명시적 형변환
 - 사용방식
 ```cpp
	float a = 3.3f;
	int b = static_cast<int>(a);
 ```
2. dynamic_cast
 - 클래스 형변환 (다운캐스팅, 업캐스팅)
 - 사용방식
 ```cpp
	Animal* animal = new Dog();
	Dog* dog = dynamic_cast<Dog*>(animal);
	if(dog != nullptr)
	{
		printf("dog is true\n");
	}
 ```

 3. reinterpret_cast
  - 포인터 형변환
  - 메모리배열을 유지하는 방식의 형변환
  - 사용방식
```cpp
	// 일반적인 상황에서 사용하지않음.
	// 꼭 Document에서 제공해주면 그때 사용할것.
```

## 3. 사각형과 사각형의 충돌체크
```
 게임 수학



```