#include <algorithm>
#include <deque>
#include <set>
#include <iostream>

using namespace std;

#include <deque>
#include <algorithm>

void RemoveDuplicates(std::deque<int>& data) {
    auto new_end = std::unique(data.begin(), data.end());
    data.erase(new_end, data.end());
}

int main() {
    deque <int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    RemoveDuplicates(a);
    for (auto el : a) {
        cout << el;
    }
    return 0;
}
