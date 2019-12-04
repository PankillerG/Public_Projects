#include<cmath>
#include<iostream>
#include<iterator>
#include<set>
#include<vector>

using namespace std;

int main() {
    set<long long int> first_seq;
    vector<long long int> second_seq;
    int n, k;
    cin >> n >> k;
    long long int inp;
    for (size_t i = 0; i < n; ++i) {
        cin >> inp;
        first_seq.insert(inp);
    }
    second_seq.resize(k);
    for (size_t i = 0; i < k; ++i) {
        cin >> inp;
        second_seq[i] = inp;
    }
    for (size_t i = 0; i < k; ++i) {
        auto it = first_seq.lower_bound(second_seq[i]);
        if (it != first_seq.end()) {
            if (it != first_seq.begin()) {
                long long int upper, lower;
                upper = *it;
                lower = *(--it);
                if (abs(second_seq[i] - lower) == abs(second_seq[i] - upper)) {
                    cout << lower << endl;
                } else if (abs(second_seq[i] - lower) < abs(second_seq[i] - upper)) {
                    cout << lower << endl;
                } else {
                    cout << upper << endl;
                }
            } else {
                cout << *it << endl;
            }
        } else {
            cout << *(--first_seq.end()) << endl;
        }
    }
    return 0;
}