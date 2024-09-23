## MarkDown

### markdown이란?
 - 프로그래머가 간단하게 문서를 만들때 사용하는 확장자 파일
 - 간단한 표현만으로도 스타일링을 쉽게 줄수 있습니다.

### markdown 문법

1. 줄 변경
```
---
```

--- 
2. 표 나타내기 
```
| backend | language | version | states |
| :----: |  :----:  | :----:  | :----: |
| V8 | JavaScript | 7.4+| done |
| JavaScriptCore | JavaScript | 7604.1.38.0.7+| done |
| Node.js | JavaScript | 14.x+ | done |
| QuickJs | JavaScript | 2024-01-13 | done |
| WebAssembly | JavaScript | Emscripten-2.0.5+ | done |
| Lua | Lua | 5.4+ | done |
| CPython | Python |  | todo |
| YARV | Ruby |  | todo |
| Mono | C# |  | todo |
```
3. 제목표현
```
 # 제목1
 ## 제목2
 ### 제목3
 #### 제목4
 ##### 제목5
 # 이 많아질수록 글자크기가 작아집니다.
```

4. 볼드체 / 취소표현 / 이텔릭표현
```
 *이텔릭체*
 **볼드체**
 ~~취소표현~~
```
5. 목록
```
- 순서가 없을때는 - 로 표현
1. 순서가 있을떄는 숫자로 로 표현 
	그 아래에서는 탭으로
```
 - 첫번째
     - 두번째 
	 - 세번째

 1. 일번
 2. 이번
     1. 2-1번

6. 하이퍼링크
```
 [GOOGLE](https://google.com)
 [문구](링크)
```
[GOOGLE](https://google.com)

7. 이미지
```
 ![대체텍스트](이미지링크)
```
![대체텍스트](data:image/jpeg;base64,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)

8. 인용문
```
> 인용문
```
> 인용문1
>> 인용문2


9. [``` ```] 코드블럭
```cpp
 int a = 3;
 printf("%d", &a);
```