#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> getNextArray(list<int> dArr) {
    bool isPlus = false;
    for (auto it = dArr.rbegin(); it != dArr.rend(); ++it) {
        *it += 1;
        if (*it != 10) break;
        *it = 0;
    }

    if (dArr.front() == 0) dArr.push_front(1);

    return dArr;
}

vector<int> getNextArray2(vector<int> A) {
    ++A.back();
    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
        A[i] = 0; ++A[i - 1];
    }

    if (A.front() == 10) {
        A[0] = 1;
        A.emplace_back(0);
    }

    return A;
}

int main() {
    int n;
    cout << "D :  " << endl;
    cin >> n;

    string d = to_string(n);
    list<int> arr;
    for (int i = 0; i < d.length(); ++i) {
        arr.push_back(d[i] - 48);
    }

//    for (const auto &item: arr) {
//        cout << item << endl;
//    }

    for (const auto &item: getNextArray(arr)) {
        cout << item << endl;
    }
}