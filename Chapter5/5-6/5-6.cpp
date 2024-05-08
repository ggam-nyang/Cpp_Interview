#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int getMaxProfit(vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;

    int buyIndex = 0;
    int sellIndex = 0;

    int maxProfit = 0;

    while (sellIndex < A.size()) {
        if (A[buyIndex] < A[sellIndex]) {
            maxProfit = max(maxProfit, A[sellIndex] - A[buyIndex]);
        } else {
            buyIndex = sellIndex;
        }
        ++sellIndex;
    }

    return maxProfit;
}

// double로 하는 것이 좋다
int getMaxProfit2(vector<int> *A_ptr) {
    int min_price_so_far = numeric_limits<int>::infinity(), max_profit = 0;
    for (int price: *A_ptr) {
        int max_profit_sell_today = price - min_price_so_far;
        max_profit = max(max_profit, max_profit_sell_today);
        min_price_so_far = min(min_price_so_far, price);
    }

    return max_profit;
}

int main() {
    vector<int> A;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int price;

        cin >> price;
        A.push_back(price);
    }

    cout << getMaxProfit(&A) << endl;
}