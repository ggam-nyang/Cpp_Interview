#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string IntToString(int x) {
    string s;
    while (x > 0) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    std::reverse(s.begin(), s.end());

    return s;
}

int StringToInt(const string &s) {
    bool isMinus = false;
    if (s[0] == '-') isMinus = true;

    int startIndex = isMinus ? 1 : 0;
    int x = 0;
    for (int i = s.size() - 1, j = 0; i >= startIndex; --i, ++j) {
        x += (s[i] - '0') * pow(10, j);
    }

    return isMinus ? -x : x;
}

//  ============== 해법 ==============
string IntToString2(int x) {
    bool isMinus = x < 0;

    string s;
    do {
        s += '0' + abs(x % 10);
        x /= 10;
    } while (x);

    s += isMinus ? "-" : "";
    return {s.rbegin(), s.rend()};
}

int StringToInt2(const string &s) {
    return (s[0] == '-' ? -1 : 1) * accumulate(begin(s) + (s[0] == '-' || s[0] == '+'), end(s), 0,
                                               [](int running_sum, char c) { return running_sum * 10 + c - '0'; });
}

int main() {

}