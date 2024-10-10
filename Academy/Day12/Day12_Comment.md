﻿# Day 12
## 바이너리트리

장점 : 
 - 찾는게 빠릅니다.
 (15개 데이터에서 내가 원하는 데이터를 걸리는 시간이 3번 서치로 끝납니다.)
 O(logN)

단점 : 
 - 순회가 복잡하다.
 - 데이터추가도 빠른편이 아닙니다.
   O(logN) 
 - 데이터삭제도 빠른편이 아닙니다.
   O(logN)

Tree랑 Vector 이거는 평생쓸거니까 꼭 기억해주세요.
코드까진 기억을못해도 원리는 꼭 기억해주세요.

### Red Black Tree
- 균등하게 높이를 조절해주는 트리
- 중앙 노드를 바꾸어주며 높이를 조절

### Map
- Red Black Tree 기술을 활용
-  데이터를 데이터 그자체로 활용하지 않고 key,value로 나눠 사용

```
10, 12, 13 의 경우
바이너리 -> 10 중앙, 우 12, 우 13 -> 높이 3
레드블랙 -> 12를 중앙노드, 10, 13을  좌우 노드로 배치 -> 높이 2
```