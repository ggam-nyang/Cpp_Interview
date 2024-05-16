## 주식 두 번 사고팔기
이번에는 주식 한 주를 최대 두 번까지 매매할 수 있을 때, 최대 이윤을 구하는 프로그램을 작성하라. 단, 두 번째 주식은 첫 번째 주식을 판 뒤에 구입할 수 있다.

### 1차
무식한 방법은 주식 한 번 사고팔기를 이용하는 것이다.  
모든 원소 N에 대해, 각 원소를 첫번쨰 주식을 파는 순간으로 지정한다.  
이 경우 왼쪽 배열, 오른쪽 배열이 나누어지는데 각 배열에 대해 주식 팔기 연산을 수행한다.  
시간 복잡도는 O(n^2), 공간 복잡도는 O(1)이다.

```markdown
// 테스트 결과
Test PASSED (400/402) [  12 us]
Test PASSED (402/402) [  56  s]
Average running time:  287 ms
Median running time:    68 us
```

O(n^2)인만큼 데이터가 많은 경우 56초나 걸렸다.  
O(n) 혹은 O(nlogn)등의 방법을 생각해보자.
### 테스트
이번 문제부터는 [EPIJudge](https://github.com/adnanaziz/EPIJudge?tab=License-1-ov-file)를 이용해 테스트했다.

### 힌트
i + 1번째 원소를 다룰 때, i개의 원소에서 어떤 정보를 얻어야 하는지 생각해보자.

음.. 방법을 잘 모르겠다. 첫번째 복권의 최대 이익은 알 수 있는데, i번째 원소에서 2번째 복권의 이익을 알 수 없다..!  
결국 dp처럼 쌓아둔 후, 다시 한번 순회하며 최대 이익을 구해야 할 것 같다.


### 해법
1번의 방법은 비효율이다.  
1개를 사고 파는 것과 동일하게 생각해서, 1번째 복권을 사고 팔 떄 최대 이익을 모든 원소에 대해 구한다.  
이후 역순으로 순회하며 2번째 복권을 사고 팔 때 최대 이익을 구한다.  

이때, 둘의 합이 최대가 되는 i가 최대 이익이 된다.

```markdown
테스트 결과
Test PASSED (402/402) [   1 ms]
Average running time:   10 us
Median running time:     2 us
```




