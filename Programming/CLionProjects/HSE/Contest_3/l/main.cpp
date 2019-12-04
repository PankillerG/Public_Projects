#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n, many, mark;
    string name;
    map <string, map<int, int>> all;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> many;
        for (size_t j = 0; j < many; j++) {
            cin >> name >> mark;
            all[name][i] = mark;
        }
    }
    for (auto name : all) {
        cout << name.first;
        for (size_t i = 0; i < n; i++) {
            cout << "\t" << name.second[i];
        }
        cout << "\n";
    }
    return 0;
}
