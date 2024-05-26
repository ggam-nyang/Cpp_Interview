#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void ReverseWords(string *s) {
    std::reverse(s->begin(), s->end());

    size_t start = 0, finish;
    while ((finish = s->find(" ", start)) != string::npos) {
        std::reverse(s->begin() + start, s->begin() + finish);
        start = finish + 1;
    }
    std::reverse(s->begin() + start, s->end());

    return;
}

int main() {

}
