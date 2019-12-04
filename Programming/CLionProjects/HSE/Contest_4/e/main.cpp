#include <iostream>
#include <iterator>
#include <list>
#include <map>


using namespace std;

int main() {
    int n;
    cin >> n;
    int num_1, num_2;
    map <int, _List_iterator<int>> num_it;
    list <int> players;
    for (size_t i = 0; i < n; i++) {
        cin >> num_1;
        cin >> num_2;
        if (num_it.find(num_2) != num_it.end()) {
            auto local = players.insert(num_it[num_2], num_1);
            num_it[num_1] = local;
        } else {
            auto local = players.insert(players.end(), num_1);
            num_it[num_1] = local;
        }
    }
    for (auto i = players.rbegin(); i != players.rend(); i++) {
        cout << *i << "\n";
    }
    return 0;
}
