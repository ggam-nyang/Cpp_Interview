## 로마 숫자를 10진수로 바꾸기
로마 숫자는 문자 집합 I, V, X, L, C, D, M을 이용해 자연수를 표현한다.  
I 1, V 5, X 10, L 50, C 100, D 500, M 1000  이다.
- I는 V, X 바로 전에 올 수 있다.
- X는 L, C 바로 전에 올 수 있다.
- C는 D, M 바로 전에 올 수 있다.

이때 로마 숫자를 10진수로 변경하는 프로그램을 작성하라.


### 1차
단순한 방법은 맨 앞부터 순회하며 계산하는 것이다.  
V,X  L,C, D,M 등은 앞에 I,X,C에 따라 값이 변한다. 그 외에는 앞에서부터 값을 더 해주면된다.

i = 1부터 n까지 순회하고, i-1 값을 저장해두고 처리한다.  
즉, i-1값에 예외처리를 하고, i-1값을 전체 합에 더 해준다.  

결과 1us 미만으로 모두 통과했다.


### 해법
뒤에서부터 순회한다.  값이 작아졌을 경우는 빼고, 아니면 더 해주는 간단한 방식으로 구현이 가능하다!!  
그러나 IC와 같은 잘못된 입력에 대해서는, 잘못된 값이 구해지긴한다.  


### 응용
입력이 유효한지 판단하는 것은, 해법과 매우 유사하다. 값이 작아지는 경우가 생겼을 때, 예외사항인지 체크해주면 된다.

