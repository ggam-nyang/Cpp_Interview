#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int SSDecodeColID(const string& col) {
    return std::accumulate(col.begin(), col.end(), 0, [](int running_sum, char c) {
        return running_sum * 26 + c - 'A' + 1;
    });
}

int main() {

}