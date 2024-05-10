#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

using namespace std;

double BuyAndSellStockOnce(const vector<double> &prices) {
    double min_price_so_far = std::numeric_limits<double>::infinity(), max_profit = 0;
    for (double price: prices) {
        double max_profit_sell_today = price - min_price_so_far;
        max_profit = std::max(max_profit, max_profit_sell_today);
        min_price_so_far = std::min(min_price_so_far, price);
    }

    return max_profit;
}

double BuyAndSellStockTwice(const vector<double> &prices) {
    double max_profit = 0;

    for (auto it = prices.begin(); it != prices.end(); ++it) {
        double curr_price = BuyAndSellStockOnce(vector<double>(prices.begin(), it + 1)) +
                            BuyAndSellStockOnce(vector<double>(it, prices.end()));
        max_profit = std::max(max_profit, curr_price);
    }

    return max_profit;
}

int main() {
    vector<double> A;
    int N;
    cin >> N;
}