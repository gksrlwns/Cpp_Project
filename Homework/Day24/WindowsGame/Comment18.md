## Flipbook
---


```
 Unity 
 Unreal

 2d sprite animation

 Flipbook 이란? 
  
  여러개의 스프라이트를 연속으로 변경시켜서 
  애니메이션처럼 보이게하는 방법

 유니티는 Animator라고 2d랑 3d랑 통합시켰어요.
```

```
 Flipbook - 2D Animation

 (Sprite Sheet)

 원리는 간단해요.
 준비해야할것 - 여러개의 스프라이트

 스프라이트 - Texture의 일부

 저희만의 SpriteSheet를 만들어줄겁니다.
  - 엔진에서는 알아서 영역찾아서 분리해주고 하거든요
  - 저희는 Texture를 격자로 나눈다음에
   - 그영역을 잘라서 Sprite로 쓸겁니다.

   + start ~ end까지 보여지는데 총 몇초가 걸리는지
   + 이 애니메이션은 반복을 하는지
```

```cpp
//Flipbook은 아래내용을 가지고있습니다

 Texture* texture;
 Vector2Int Size;
 int start;
 int end;
 int line; 
 float duration;
 bool loop;
```



---
### 숙제 
```
1.
 캐릭터 하나 생성해서
 wasd로 움직임
 마우스왼쪽키로 공격 하는 캐릭터 구현

2.
 공격시 총알 발사되도록.

3.
 공격한 총알이 장애물이나 적군에게 맞으면 적군 제거

4. 
 장애물이나 적군에게 HP 부여해서 한대맞고는 안죽게
```
#### 리소스가 탑뷰형식 리소스여야해요.
