#include <iostream>
#include <vector>
#include <algorithm>

template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    std::vector <It> all;
    while (first2 != last2) {
        all.push_back(first2);
        first2++;
    }
    std::reverse(all.begin(), all.end());
    size_t i = 0;
    bool flag = true;
    while (flag) {
        if (i == all.size() &&
        first1 == last1) {
            flag = false;
            break;
        }
        if (first1 == last1) {
            *out = *all[i];
            out++;
            i++;
        } else if (i == all.size()) {
            *out = *first1;
            out++;
            first1++;
        } else {
            if (*first1 <= *all[i]) {
                *out = *first1;
                out++;
                first1++;
            } else {
                *out = *all[i];
                out++;
                i++;
            }
        }
    }
    return out;
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
    int m;
    cin >> m;
    vector <int> c;
    c.resize(n + m);
    for (size_t i = 0; i < m; i++) {
        cin >> local;
        b.push_back(local);
    }
    sideways_merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    for (auto e : c) {
        cout << e << " ";
    }
    return 0;
}
