## 밑수 바꾸기
문자열 1개와 두 개의 정수 b1, b2가 주어졌을 때, b1진수에서 b2진수로 변환하라!


### 1차
바로 떠오르는 방법은, 10진수로 변환하여 다시 변환하는 방법이다..!  
문자열의 길이 제한이 없다고 했을 때, double로 변환하고, 다시 n진수로 변환한다.

풀고보니, 6-1과 완벽하게 동일하다..!  6-1은 IntToString이지만 사실 string -> 10진수이고,   
이번 문제는 확장된 n진수 -> string, string -> n진수이다!

시간은 1us 미만으로 성공이다 ㅎㅎ

### 해법
동일한 풀이이다. 다만, 10진수를 변환할 때 재귀를 이용했다.  반복문은 늘 재귀로 바꿀 수 있으니 당연하지만 알아두면 좋을 것 같다.  

```c++
std::string ConstructFromBase(int num_as_int, int base) {
    return num_as_int == 0 ? "" : ConstructFromBase(num_as_int / base, base) + static_cast<char>(num_as_int % base >= 10 ? 'A' + num_as_int % base - 10 : '0' + num_as_int % base);
}
```
