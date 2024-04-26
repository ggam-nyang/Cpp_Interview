/**
 * n은 어느 정도 범위인걸까?
 * n의 크기에 따라 방향이 바뀔까?
 */
// 먼저 패리티를 구하는 코드를 생각해보자

#include <iostream>
#include <vector>

using namespace std;

u_int64_t test = 0xFFFFFFFFFFFFFFFF;

// 시간복잡도 : 64 * n (최악)
// 공간복잡도 : 함수를 n번 호출, n개의 입력 ...

int getParity(unsigned long long x) {
    short count = 0;

    while (x) {
        count ^= (x & 1);
        x >>= 1;
    }

    return count;
}

// O(k)인 방법, x & (x - 1)이 가장 아래 1을 지우는 방법이다..!
int getParity2(unsigned long long x) {
    short result = 0;

    while (x) {
        result ^= 1;
        x &= (x - 1);
    }

    return result;
}

// O(n/L)인 방법, n은 총 비트 개수, L은 자르는 비트 단위의 크기(16)이다.
int getParity3(unsigned long long x) {
    static vector<short> precomputedParity(1 << 16);
    const int kMaskSize = 16;
    const int kBitMask = 0xFFFF;

    return precomputedParity[x >> (3 * kMaskSize)] ^
           precomputedParity[(x >> (2 * kMaskSize)) & kBitMask] ^
           precomputedParity[(x >> kMaskSize) & kBitMask] ^
           precomputedParity[x & kBitMask];
}

// XOR는  결합법칙과 순서를 바꾸어도 결과가 같다는 교환법칙이 성립
// 즉 16비트 4개의 패리티를 xor 하는게 아닌, 16비트 4개를 xor 한 값의 패리티를 구하는 것
int getParity4(unsigned long long x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 1;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        uint64_t input;
        cin >> input;

        cout << getParity(input) << endl;
    }
}