#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int ConvertTen(const string& num_as_string, int b1) {
    return accumulate(num_as_string.begin(), num_as_string.end(), 0,
                      [b1](int sum, char c){ return sum * b1 + c >= 'A' ? c - 'A' + 10 : c - '0'; });
}

string ConvertBase(const string& num_as_string, int b1, int b2) {
    int decimalNum = ConvertTen(num_as_string, b1);
    string ans;
    do {
        int temp = decimalNum % b2;

    } while (decimalNum)

    return "";
}

int main() {

}