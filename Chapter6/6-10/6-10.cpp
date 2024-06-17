#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using std::stoi;
using std::string;
using std::vector;

string SnakeString(const string& s) {
    string newS;
    for (int i = 1; i < s.size(); i += 4) {
        newS += s[i];
    }

    for (int i = 0; i < s.size(); i += 2) {
        newS += s[i];
    }

    for (int i = 3; i < s.size(); i += 4) {
        newS += s[i];
    }

    return newS;
}

int main() {

}
