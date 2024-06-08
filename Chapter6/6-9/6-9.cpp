#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using std::stoi;
using std::string;
using std::vector;

bool IsValidPart(const string& s) {
    if (s.front() == '0' && s.size() > 1) {
        return false;
    }
    int val = stoi(s);
    return val <= 255 && val >= 0;
}

vector<string> GetValidIpAddress(const string &s) {
    auto n = s.size();
    if (n < 4) return {};

    vector<string> ans;
    for (int i = 1; i < 4; ++i) {
        if (n - i > 9) continue;
        if (!IsValidPart(s.substr(0, i))) break;
        for (int j = i + 1; j <= i + 3; ++j) {
            if (n - j > 6) continue;
            if (!IsValidPart(s.substr(i, j - i))) break;
            for (int k = j + 1; k <= j + 3; ++k) {
                if (n - k > 3) continue;
                if (n - k <= 0) break;
                if (!IsValidPart(s.substr(j, k - j))) continue;
                if (!IsValidPart(s.substr(k))) continue;

                string newIp = s.substr(0, i) + "." + s.substr(i, j - i) + "." + s.substr(j, k - j)
                               + "." + s.substr(k);
                ans.push_back(newIp);
            }
        }
    }
    return ans;
}

int main() {

}

//bool IsValidPart(const string& s);
//
//vector<string> GetValidIpAddress(const string& s) {
//    vector<string> result;
//    for (size_t i = 1; i < 4 && i < size(s); ++i) {
//        if (const string first = s.substr(0, i); IsValidPart(first)) {
//            for (size_t j = 1; i + j < size(s) && j < 4; ++j) {
//                const string second = s.substr(i, j);
//                if (IsValidPart(second)) {
//                    for (size_t k = 1; i + j + k < size(s) && k < 4; ++k) {
//                        const string third = s.substr(i + j, k),
//                                fourth = s.substr(i + j + k);
//                        if (IsValidPart(third) && IsValidPart(fourth)) {
//                            result.emplace_back(first + "." + second + "." + third + "." +
//                                                fourth);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return result;
//}
//
//bool IsValidPart(const string& s) {
//    if (size(s) > 3) {
//        return false;
//    }
//    // "00", "000", "01", etc. are not valid, but "0" is valid.
//    if (s.front() == '0' && size(s) > 1) {
//        return false;
//    }
//    int val = stoi(s);
//    return val <= 255 && val >= 0;
//}