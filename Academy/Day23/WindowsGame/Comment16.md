## Collision Manager

충돌체크를 관리하는 역할

게임엔진들 보면
Collider 라고 있습니다.

### Collider Component
해당 오브젝트를 충돌체로 만들어주는 역할을 해줌.


### Collider 종류
 1. Circle Collider
     - 원형 충돌체
 2. Box Collider
     - 네모난 충돌체


### Collision Manager
 - A collider와 B collider가 충돌했다. 라는걸 알려줌.
     - OnTriggerEnter ( 충돌이 시작하였을 때 ) 
     - OnTriggerExit (충돌이 끝났을 때)
 - Collider 입장에서는
    - 모든 애랑 충돌하면 원하는 기능이 안나오거나, 너무 성능이 과부하됩니다.
    - 게임에서 (그래픽을 제외하고) 가장 무거운 기능이 충돌체크
    - 그렇기 때문에 최대한 내가 원하는 객체랑만 충돌하도록 설정
        - Collision Layer를 따로 만들어 줌.

### Collision Layer
 - Character = 0 (2의 0제곱)
 - Ground = 1 (2의 1제곱)
 - Item = 2 (2의 2제곱)

 이랬을때 
  - Character입장에서는 Ground, Item이 모두 충돌체크가 되어야함.
  - Ground 입장에서는 Character만 충돌체크되면 됩니다.
  - Item 입장에서도 Character만 충돌체크되면 됩니다.

### 비트연산
 (추후에 코딩테스트에서도 많이 활용됩니다.)

  - int32 (4byte) (32bit) 변수로 비트연산을 할겁니다.
  - 0000 0000 0000 0000 0000 0000 0000 0000

  - 0000 0000 0000 0000 0000 0000 0000 0111 
      - Character, Ground, Item 모두 충돌체크한다.

  - 0000 0000 0000 0000 0000 0000 0000 0110
      - Ground, Item 모두 충돌체크한다.

      - Ground = 1 이라는 변수가 들어왔을때 (2의 1제곱이) 이 비트에 포함되어있는지를 검사합니다.

### 비트연산자
```
 & - and
 010 & 110 =>  010

 | - or
 010 | 110 =>  110


 ~ - not
 ~110 => 001

 int32 
 ~(0000 0000 0000 0000 0000 0000 0000 0000)
 (1111 1111 1111 1111 1111 1111 1111 1111)
```


### 실습내용
```cpp
1. 함수 세개 구현
	virtual bool CheckCollision(Collider* other);
    void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);

2. Day22Scene 실행하였을 때 
  충돌체크가 잘되었다는 문구 뜨게끔
```

```cpp
 비트연산의 일종인데

 << 연산자
 >> 연산자

 3 << 2 = 12
 0011(3) << 2 = 1100 (12)
```

#### 여담
```
취업관련
 - 신입으로 지원

 - 생각보다 신입의 컷이 높지 않아요.

 - 이중포문을 못쓰는 신입을 봤습니다.
   (좀 이름있는 회사에요.) 
   
   운입니다.

   서류통과부터 운이고
   (엄청나게 잘나거나 특출난게 아니면)

   특히 면접은 실장님 한마디로 컷당할수도있고
   (관상이 별론데)

   뽑기로 다 결정되고 팀내부에서는 무조건 뽑자 
   이런의견까지 나왔는데

   뽑으려고 인사팀에 안내해달라고하니까
   갑자기 TO가 없어짐

   아무도 안뽑고 공고가 내려가는

   
   지원자 입장에서도
   지원할 회사가 별로없는데

   웃긴게 구인하는 입장에서도
   (쓸만한) 사람이 별로없어요

   신입 면접에서는 내가 잘한다 << (X)
   내가 성장할 사람이다. (싹이 보인다.) (O)
```