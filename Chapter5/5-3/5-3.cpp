#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

vector<int> getMultiple1(vector<int> a, vector<int> b) {
    // 배열의 이중 반복문으로 곱셈
    // 근데 곱셈의 결과도 매우 큰 정수...! 덧셈이 안됨
    // 각 자릿수의 곱셈의 결과를 배열로 만들고, 배열의 덧셈을 구현.. 매우 비효율적일듯
    // 그치만 방법이 없는듯?
    int sign = (a.front() < 0 ? -1 : 1) * (b.front() < 0 ? -1 : 1);
//    int sign = (a.front() < 0) ^ (b.front() < 0) ? -1 : 1; 비트연산!!

    a.front() = abs(a.front()); b.front() = abs(b.front());
    vector<int> sum(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            sum[i + j + 1] += a[i] * b[j];
            sum[i + j] += sum[i + j + 1] / 10;
            sum[i + j + 1] %= 10;
        }
    }

    sum = {
            find_if_not(begin(sum), end(sum), [](int a) { return a == 0; }),
            end(sum)
    };
    if (empty(sum)) {
        return {0};
    }
    sum.front() *= sign;

    return sum;
}

int main() {
    string a;
    string b;

    cin >> a >> b;

    vector<int> A(a.begin(), a.end());
    vector<int> B(b.begin(), b.end());

    for_each(A.begin(), A.end(), [&](auto &item) {
        item -= 48;
    });

    for_each(B.begin(), B.end(), [&](auto &item) {
        item -= 48;
    });

    for (const auto &c: getMultiple1(A, B)) {
        cout << c << endl;
    }
}