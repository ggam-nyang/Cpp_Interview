#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

using namespace std;
void Rearrange(vector<int>* A_ptr) {
    vector<int> &A = *A_ptr;
    std::sort(A.begin(), A.end());

    int left = 1;
    int right = A.size() % 2 == 0 ? A.size() - 2 : A.size() - 1;

    while (left < right) {
        int temp = A[left];
        A[left] = A[right];
        A[right] = temp;

        left += 2;
        right -= 2;
    }

    return;
}

void RearrangeBubble(vector<int>* A_ptr) {
    vector<int> &A = *A_ptr;
    for (int i = 1; i < A.size(); ++i) {
        if (((i % 2 == 0) && A[i] > A[i - 1]) || ((i % 2 == 1) && A[i] < A[i - 1])) {
            std::swap(A[i - 1], A[i]);
        }
    }

    return;
}


int main() {

}