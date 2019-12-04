#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    multiset <int> num_set;
    vector <int> num_vect;
    int local;
    for (size_t i = 0; i < k; i++) {
        cin >> local;
        num_set.insert(local);
        num_vect.push_back(local);
    }
    cout << *num_set.begin() << "\n";
    for (size_t i = k; i < n; i++) {
        cin >> local;
        num_vect.push_back(local);
    }
    for (size_t i = k; i < n; i++) {
        num_set.erase(num_set.lower_bound(num_vect[i - k]));
        num_set.insert(num_vect[i]);
        cout << *num_set.begin() << "\n";
    }
    return 0;
}
