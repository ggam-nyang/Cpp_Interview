#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

int removeDuplicate(list<int> &list) {
    int dupCnt = 0;
    if (list.size() <= 1) return list.size();

    auto before = *list.begin();
    for (auto it = ++list.begin(); it != list.end() ;) {
        if (*it < before) break;
        if (*it == before) {
            list.push_back(*it);
            it = list.erase(it);
            ++dupCnt;
            continue;
        }
        before = *it;
        ++it;
    }

    return list.size() - dupCnt;
}

int removeDuplicate2(vector<int> &A) {
    if (empty(A)) {
        return 0;
    }

    int write_index = 1;
    for (int i = 1; i < size(A); ++i) {
        if (A[write_index - 1] != A[i]) {
            A[write_index++] = A[i];
        }
    }

    return write_index;
}

int removeDuplicate3(vector<int> &A, int key) {
    if (empty(A)) {
        return 0;
    }

    int write_index = 0;
    for (int i = 0; i < size(A); ++i) {
        if (A[i] != key) {
            A[write_index++] = A[i];
        }
    }

    return write_index;
}

int main() {
    int N;
    cin >> N;

    list<int> A;
    vector<int> B;

    for (int i = 0; i < N; ++i) {
        int ele;
        cin >> ele;
        A.push_back(ele);
        B.push_back(ele);
    }


//    cout << removeDuplicate(A) << endl;
//    cout << removeDuplicate2(B) << endl;
    cout << removeDuplicate3(B, 2) << endl;
}