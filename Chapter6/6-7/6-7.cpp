#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
string LookAndSay(int n) {
    string v[n + 1];
    v[1] = "1";

    for (int i = 2; i <= n; ++i) {
        int count = 0;
        char curr = ' ';
        v[i] = "";
        for (const auto &c : v[i - 1]) {
            if (curr == ' ') {
                curr = c;
                count = 1;
                continue;
            }

            if (curr == c) {
                ++count;
            }

            if (curr != c) {
                v[i] += to_string(count) + curr;
                curr = c;
                count = 1;
            }
        }

        v[i] += to_string(count) + curr;
    }

    return v[n];
}

string NextNumber(const string& s) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
        int count = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1]) {
            ++i, ++count;
        }
        result += to_string(count) + s[i];
    }
    return result;
}

string LookAndSay2(int n) {
    string s = "1";
    for (int i = 1; i < n; ++i) {
        s = NextNumber(s);
    }

    return s;
}

int main() {

}
