#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int maxn = 1e5 + 228;
int p[maxn];
int r[maxn];
set<int> s;
int n, m;

void make_sets() {
    for (size_t i = 0; i < maxn; ++i) {
        p[i] = i;
        r[i] = 1;
    }
}

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) {
        return;
    }
    if (a > b) {
        swap(a, b);
    }
    p[b] = a;
    r[a] += r[b];
}

int main() {
    cin >> n
        >> m;
    for (size_t i = 0; i < n; ++i) {
        s.insert(i);
    }
    make_sets();
    for (size_t i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == 'c') {
            if (s.size() == 0) {
                cout << -1 << "\n";
            } else {
                cout << *s.begin() + 1 << "\n";
            }
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            x = find_set(x);
            y = find_set(y);
            if (x == y) {
                continue;
            }
            int ch1 = r[x] % 2, ch2 = r[y] % 2;
            union_sets(x, y);
            if (ch1 == 0 && ch2 == 1) {
                if (p[y] == x) {
                    s.erase(y);
                    s.insert(x);
                }
            } else if (ch1 == 1 && ch2 == 0) {
                if (p[x] == y) {
                    s.erase(x);
                    s.insert(y);
                }
            } else if (ch1 == 1 && ch2 == 1) {
                s.erase(x);
                s.erase(y);
            }
        }
    }
    return 0;
}

