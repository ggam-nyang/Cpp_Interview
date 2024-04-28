#include <iostream>
#include <vector>

using namespace std;


// 공간복잡도를 고려하지 않았을 때, O(n)
vector<int> makeFlag1(vector<int> v) {
    vector<int> small;
    vector<int> same;
    vector<int> large;

    int pivot = v.size() / 2;
    for (const auto &ele: v) {
        if (ele < v[pivot]) small.emplace_back(ele);
        else if (ele == v[pivot]) same.emplace_back(ele);
        else large.emplace_back(ele);
    }
    vector<int> answer;
    for (const auto &item: small) {
        answer.push_back(item);
    }

    for (const auto &item: same) {
        answer.push_back(item);
    }

    for (const auto &item: large) {
        answer.push_back(item);
    }

    return answer;
}

vector<int> makeFlag2(vector<int> v) {
    int left = 0;
    int right = v.size() - 1;
    int mid = (left + right) / 2;

    while (left < right) {
        if (v[left] < v[mid]) ++left;
        else if (v[left] > v[mid]) swap(v[left], v[right--]);
        else {
            if (v[left] == v[left + 1]) break;
            swap(v[left], v[left + 1]);
        }
    }

    return v;
}

int main() {
    int n;
    cout << "배열 개수 : " << endl;
    cin >> n;

    int arr[n];
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    for (const auto &item: makeFlag2(vec)) {
        cout << item << endl;
    }
}