#include<iostream>
#include<iterator>
#include<list>
#include<map>

using namespace std;

int main() {
    list<int> players;
    map<int, _List_iterator<int>> positions;
    int n;
    cin >> n;
    int number, pos;
    for (size_t i = 0; i < n; ++i) {
        cin >> number >> pos;
        if (positions.find(pos) == positions.end()) {
            auto it = players.insert(players.end(), number);
            positions[number] = it;
        } else {
            auto it = positions[pos];
            auto ins = players.insert(it, number);
            positions[number] = ins;
        }
    }
    for (auto it = players.rbegin(); it != players.rend(); ++it)
        cout << *it << endl;
    return 0;
}
