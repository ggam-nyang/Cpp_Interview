#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool IsPalindromic(const string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        while (!(65 <= s[left] && s[left] <= 90) && !(97 <= s[left] && s[left] <= 122)) {
            ++left;
        }

        while (!(65 <= s[right] && s[right] <= 90) && !(97 <= s[right] && s[right] <= 122)) {
            --right;
        }

        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }

    return true;
}

int main() {
    char a = 'a';
    char c = 'A';

    if (a == c) cout << "hi";
}