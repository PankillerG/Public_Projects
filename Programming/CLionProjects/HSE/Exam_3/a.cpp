#include <algorithm>
#include <deque>
#include <set>
#include <iostream>

using namespace std;

void RemoveDuplicates(std::deque<int>& data) {
    set <int> local;
    for (auto i = data.begin(); i != data.end();) {
        if (local.find(*i) != local.end() && i != data.end()) {
            data.erase(i);
        } else {
            local.insert(*i);
            i++;
        }
    }
}

int main() {
    deque <int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    RemoveDuplicates(a);
    for (auto el : a) {
        cout << el;
    }
    return 0;
}
