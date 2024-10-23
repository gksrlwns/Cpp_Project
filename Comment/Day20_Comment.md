# Day 20
## map
- ResourceManager에서 미리 리소스를 받아와서 재사용하기 위해 사용
- 검색속도가 빠름
``` cpp
//item.first -> 키값
//item.second -> value
for (auto& item : _resoureces)
	{
		SAFE_DELETE(item.second);
	}
```

## 랜덤 매니저
```
 그동안은 랜덤을

 rand() 사용했습니다.

 그렇게 잘 분포되어있지 않아요.
 범위도 
 0 ~ 25000정도로 범위도 짧고

 0한번뜰때 1이 한번뜬다는 그정도 분포를 항상 가지고있지않습니다.

 더 좋다는 랜덤엔진으로 변경 + 모듈화를 할겁니다.

 랜덤엔진 - MT19937  (카지노에서 주로쓰는 랜덤엔진)
```
