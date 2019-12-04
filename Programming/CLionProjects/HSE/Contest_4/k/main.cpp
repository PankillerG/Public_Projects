#include <cmath>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    set <long long> first;
    long long local;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        first.insert(local);
    }
    for (size_t i = 0; i < k; i++) {
        cin >> local;
        if (first.lower_bound(local) == first.begin()) {
            cout << *first.begin() << "\n";
        } else if (first.lower_bound(local) == first.end()) {
            cout << *first.rbegin() <<"\n";
        } else {
            if (abs(local - *(--first.lower_bound(local))) <=
            abs(local - *first.lower_bound(local))) {
                cout << *(--first.lower_bound(local)) << "\n";
            } else {
                cout << *first.lower_bound(local) << "\n";
            }
        }
    }
    return 0;
}
