## 반복 길이 부호화로 문자열을 압축 해제하기
"aaaabcccaa" "4a1b3c2a"가 된다.  
반복 길이 부호화를 사용해서 문자열의 압축 및 해제를 구현하라.

### 1차
문제는 간단하다.  먼저 압축부터 구현하자.  
압축은 다른 알파벳이 나오면 숫자 + 알파벳을 추가하고, 같은 문자열이면 카운트만 증가하는 방식으로 구현했다.  

해제는 비슷하게, 숫자라면 카운트를 기록하고 알파벳이라면 해당 카운트만큼 알파벳을 추가했다.  

간단한 방식으로 구현이 가능했다.

시간복잡도는 모두 O(n)이다.