#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> A;

bool CanReach1() {
    vector<bool> visited(A.size() + 1, false);
    deque<int> q;
    q.push_back(0);
    visited[0] = true;

    while (!q.empty()) {
        int currIdx = q.front();
        q.pop_front();

        for (int i = 1; i <= A[currIdx]; ++i) {
            int newIdx = currIdx + i;
            if (newIdx == A.size() - 1) return true;

            if (newIdx < A.size() && A[newIdx] != 0 && !visited[newIdx]) {
                q.push_back(newIdx);
                visited[newIdx] = true;
            }
        }
    }

    return false;
}

bool CanReach2() {
    int furthest_reach_so_far = 0;
    int last_index = A.size() - 1;

    for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) {
        furthest_reach_so_far = max(furthest_reach_so_far, A[i] + i);
    }
    return furthest_reach_so_far >= last_index;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int ele;
        cin >> ele;
        A.push_back(ele);
    }


    cout << CanReach1() << endl;
}