#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int ReplaceAndRemove(int size, char s[]) {
    int writeIdx = 0, aCnt = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] != 'b') {
            s[writeIdx++] = s[i];
        }
        if (s[i] == 'a') {
            ++aCnt;
        }
    }

    int currIdx = writeIdx - 1;
    writeIdx = currIdx + aCnt;
    const int finalSize = writeIdx + 1;
    while (currIdx >= 0) {
        if (s[currIdx] == 'a') {
            s[writeIdx--] = 'd';
            s[writeIdx--] = 'd';
        } else {
            s[writeIdx--] = s[currIdx];
        }
        --currIdx;
    }

    return finalSize;
}

int main() {

}