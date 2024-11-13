﻿### 코딩테스트 참고하면 좋은 내용.


#### 제약사항보기 (편법 체크입니다.)
```
범위가 1 ≤ n ≤ 100,000
10만이면 O(n^2)
```

```
범위가 1 ≤ n ≤ 1,000,000
100만이면 O(n)
```

```
범위가 1 ≤ n ≤ 1,000,000
범위가 1 ≤ k ≤ 1,000,000

n개의 배열길이에서 k의 수를 계속 더해야하는 문제다.

1,000,000 * 1,000,000 의 범위가 
int형이 되는지, int64로 해야하는지

배열 N이 있는데, N의 길이를 모두 더한 값을 구하시오.
N = [1, 2, 3]

코딩하기 쉬우려고 int로 그냥 무의식중에 합니다.

N의 요소를 k라고 지정할때
k의 범위는
범위가 1 ≤ k ≤ 1,000,000
n의 길이는 
범위가 1 ≤ n ≤ 1,000,000
```