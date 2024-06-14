#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <random>

using namespace std;

void RandomSampling_Shuffle(int k, vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(A.begin(), A.end(), gen);
}

void RandomSampling(int k, vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    std::default_random_engine seed((std::random_device()) ());
    for (int i = 0; i < k; ++i) {
        std::swap(A[i], A[std::uniform_int_distribution<int>{i, static_cast<int>(A.size()) - 1}(seed)]);
    }
}

int main() {

}