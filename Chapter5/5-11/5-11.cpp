#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<int> NextPermutation(vector<int> perm) {
    for (int i = perm.size() - 1; i > 0; --i) {
        if (perm[i - 1] < perm[i]) {
            int targetIdx = perm.size() - 1;
            for (int j = i; j < perm.size(); ++j) {
                if (perm[i - 1] >= perm[j]) {
                    targetIdx = j - 1;
                    break;
                }
            }
            std::swap(perm[i - 1], perm[targetIdx]);
            sort(perm.begin() + i, perm.end());
            return perm;
        }
    }
    return {};
}

vector<int> NextPermutation2(vector<int> perm) {
    // is_sorted_until : 정렬되지 않은 첫 it 찾음
    auto inversion_point = is_sorted_until(rbegin(perm), rend(perm));
    if (inversion_point == rend(perm)) {
        return {};
    }

    // 정렬되지 않은 원소와 값을 비교
    auto least_upper_bound =
            upper_bound(rbegin(perm), inversion_point, *inversion_point);

    // 스왑~
    iter_swap(inversion_point, least_upper_bound);

    // 정렬 뒤집기!
    reverse(rbegin(perm), inversion_point);
    return perm;
}

int main() {

}