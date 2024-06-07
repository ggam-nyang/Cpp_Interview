#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int RomanToIntegerC(const char& c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;

    return 0;
}

int RomanToInteger(const string& s) {
    char prev = s.front();
    int sum = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (prev == 'I') {
            if (s[i] == 'V' || s[i] == 'X') {
                sum -= 2;
            }
        }

        if (prev == 'X') {
            if (s[i] == 'L' || s[i] == 'C') {
                sum -= 20;
            }
        }

        if (prev == 'C') {
            if (s[i] == 'D' || s[i] == 'M') {
                sum -= 200;
            }
        }
        sum += RomanToIntegerC(prev);
        prev = s[i];
    }

    sum += RomanToIntegerC(prev);
    return sum;
}

int RomanToInteger2(const string& s) {
    unordered_map<char, int> T = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};

    int sum = T[s.back()];
    for (int i = s.size() - 2; i >= 0; --i) {
        if (T[s[i]] < T[s[i + 1]]) {
            sum -= T[s[i]];
        } else {
            sum += T[s[i]];
        }
    }
}

int main() {

}
