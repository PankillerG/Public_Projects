#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string local;
    int page;
    map <int, set<string>> all;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        cin >> page;
        all[page].insert(local);
    }
    for (auto elem : all) {
        cout << elem.first << " ";
        for (auto k : elem.second) {
            cout << k << " ";
        }
        cout << "\n";
    }
    return 0;
}
