#include <iostream>
#include <vector>

template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    last2--;
    for (; first1 != last1;) {
        if (first2 == last2) {
            if (*last2 < *first1) {
                *out = *last2;
                out++;
                return std::copy(first1, last1, out);
            } else {
                *out = *first1;
                first1++;
                out++;
            }
        }
        if (*last2 < *first1) {
            *out = *last2;
            last2--;
        } else {
            *out = *first1;
            first1++;
        }
        out++;
    }
    return std::copy(last2, first2, out);
}

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a;
    int local;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        a.push_back(local);
    }
    vector <int> b;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        b.push_back(local);
    }
    vector <int> c;
    c.resize(n*2);
    sideways_merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    for (auto e : c) {
        cout << e << " ";
    }
    return 0;
}
