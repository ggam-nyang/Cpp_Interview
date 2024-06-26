## 패리티 계산하기

2진수의 패리티(parity)는 1로 세팅된 비트의 개수와 같다. 즉 1이 홀수 개면 1 짝수 개면 0이 된다.  
예를 들어 1011의 패리티는 1이고, 10001000의 패리티는 0이다.  

이 패리티는 데이터를 저장하거나 네트워크로 통신을 할 떄 오류를 확인하는 용도로 사용된다. 64비트 숫자 하나의 패리티를 계산하는 코드는 쉽다.  
64비트로 이루어진 숫자가 굉장히 많다면, 어떻게 계산해야할까?


## 풀이
### 1차
N의 크기가 충분하다고 가정하고, 1개의 패리티를 구하는 방법을 단순 반복문으로 처리  
모든 비트를 확인하여 1의 개수 확인  
시간복잡도 : 64N 으로 추측

### 힌트 확인
룩업테이블을 조사해봤다.  
자주 사용하는 데이터를 배열로 저장하는 것이라고 하는데... 아마도 메모이제이션 등의 방법을 말하는게 아닐까 이해했다.

N개의 데이터간의 연관성이 없기 때문에, 결국 각 데이터에 대한 연산이 필요하다고 생각하는데... 

### 해법 확인
이때 문제를 이해했다.... 1의 개수를 세는 것이 아닌 1의 개수가 홀수인지 짝수인지 판별하는 것!

### 2차
x & (x - 1)은 가장 낮은 1인 비트를 삭제하는 방법이다...! 이를 이용해 1의 개수 k인 비트에 대해  
O(k)의 패리티 함수를 구현한다.

### 3차
비트에 대한 패리티는, 결합법칙이 성립한다. 즉 분할 정복이 가능하다  
때문에 16비트 4개로 나누어 각 결과 4개의 XOR 연산이 답이다......!
O(n/L)인 방법, n은 총 비트 개수, L은 자르는 비트 단위의 크기이다.

### 4차
XOR는  결합법칙과 순서를 바꾸어도 결과가 같다는 교환법칙이 성립
즉 16비트 4개의 패리티를 xor 하는게 아닌, 16비트 4개를 xor 한 값의 패리티를 구하는 것
O(logN)의 시간복잡도를 가진다.



