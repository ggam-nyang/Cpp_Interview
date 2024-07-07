#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string Decoding(const string &s) {
    int count = 0;
    string ans;
    for (const auto &c: s) {
        if (isdigit(c)) {
            count = count * 10 + c - '0';
        } else {
            ans.append(count, c);
            count = 0;
        }
    }

    return ans;
}
string Encoding(const string &s) {
    string ans = "";

    char curr = s.front();
    int cnt = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (curr == s[i]) ++cnt;
        else {
            ans += std::to_string(cnt) + curr;
            curr = s[i];
            cnt = 1;
        }
    }
    ans += std::to_string(cnt) + curr;

    return ans;
}

int main() {

}
