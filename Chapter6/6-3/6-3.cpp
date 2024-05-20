#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> GeneratePrimes(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i < n + 1; ++i) {
        if (!sieve[i]) continue;
        for (int j = i + i; j < n + 1; j += i) {
            sieve[j] = false;
        }
    }

    vector<int> answer;
    for (int i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) answer.push_back(i);

    }
    return answer;
}

int main() {

}