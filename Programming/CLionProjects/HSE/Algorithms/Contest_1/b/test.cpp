#include <bits/stdc++.h>

using namespace std;

const long long const_1 = 29;
const long long const_2 = 1e9 + 7;

const int maximus = 1228;
const int inf = 1e9;
int n, k;
long long vect_1[maximus][maximus];
long long vect_2[maximus][maximus];
long long vect_3[maximus][maximus];
vector<int> vect_11(maximus);

int my_func(int one,
          int two,
          int three) {
    int l;
    l = 0;
    int r;
    r = three - 1;
    int mid;
    mid = 1;
    while (r >= l) {
        mid = (l + r) / 2;
        if (vect_1[one][mid + 1] ==
            vect_1[two][mid + 1] &&
            mid + 1 < three) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (vect_1[one][l] !=
        vect_1[two][l]) {
        return 0;
    }
    return l + 1;
}


vector<string> local_l(maximus);
vector<pair<pair<int, int>, int>> g[maximus];
void dx(int s,
           int en) {
    vector <int> di(n, inf);
    vector<pair<int, int> > const_1(n);
    di[s] = 0;
    vector<char> u(n);
    for (size_t i = 0;
         i < n;
         i++) {
        int v = -1;
        for (size_t j = 0;
             j < n;
             j++)
            if (!u[j] &&
                (v == -1 ||
                di[j] < di[v]))
                v = j;
        if (di[v] == inf)
            break;
        u[v] = true;
        for (size_t j = 0;
             j < g[v].size();
             j++) {
            int to = g[v][j].first.first;
            int len = g[v][j].first.second;
            int na = g[v][j].second;
            if (di[v] + len <
                di[to]) {
                di[to] = di[v] + len;
                const_1[to] = {v, na};
            }
        }
    }
    cout << di[en]
         << "\n";
    int x = en;
    vector<int> answer;
    vector<int> ver;
    ver.push_back(en);
    while (const_1[x].first !=
           s) {
        answer.push_back(
            const_1[x].second);
        ver.push_back(
            const_1[x].first);
        x = const_1[x].first;
    }
    answer.push_back(
        const_1[x].second);
    ver.push_back(
        const_1[x].first);
    reverse(
        answer.begin(),
        answer.end());
    reverse(ver.begin(),
            ver.end());
    for (size_t i = 0;
         i < ver.size() - 1;
         i++) {
        if (answer[i] == 0) {
            cout << "up"
                 << "\n";
        } else if (answer[i] == 1) {
            cout << "down"
                 << "\n";
        } else {
            cout << "Alt"
                 << "\n";
        }
        if (answer[i] == 2) {
            for (size_t j = 0;
                 j < vect_2[ver[i]][ver[i + 1]] - 1;
                j++) {
                cout << local_l[ver[i + 1]][j]
                     << "\n";
            }
        }
    }
}


int main() {
    for (size_t i = 0;
         i < maximus;
         i++) {
        for (size_t j = 0;
             j < maximus;
             j++) {
            vect_1[i][j] = inf;
            vect_2[i][j] = inf;
            vect_3[i][j] = inf;
        }
    }
    cin >> n;
    for (size_t i = 0;
         i < n;
         i++) {
        cin >> local_l[i];
        vect_3[i][i] = 0;
    }
    cin >> k;
    for (size_t i = 0;
         i < k;
         i++) {
        cin >> vect_11[i];
    }
    for (size_t i = 0;
         i < n;
         i++) {
        long long hash = 0;
        for (size_t j = 0;
             j < local_l[i].size();
             j++) {
            vect_1[i][j] = (hash * const_1 +
                            (local_l[i][j] - 'a' + 1)) % const_2;
            hash = vect_1[i][j];
        }
    }
    for (size_t i = 0;
         i < n;
         i++) {
        for (size_t j = i + 1;
             j < n;
             j++) {
            vect_3[i][j] = my_func(
                i,
                j,
                min(
                    local_l[i].size(),
                    local_l[j].size()));
        }

        for (size_t j = 0;
             j < i;
             j++) {
            vect_3[i][j] = my_func(
                i,
                j,
                min(
                    local_l[i].size(),
                    local_l[j].size()));
        }
    }
    for (size_t i = 0;
         i < n;
         i++) {
        if (i == 0) {
            vect_2[n - 1][i] =
            vect_3[n - 1][i] + 2;
        } else {
            vect_2[i - 1][i] =
            vect_3[i - 1][i] + 2;
        }
        for (int j = 2;
             j < n;
             j++) {
            vect_2[(n + i - j) % n][i] = max(
                vect_3[(n + i - j) % n][i] + 2,
                vect_2[(n + i - j + 1) % n][i]);
        }
    }
    for (size_t i = 0;
         i < n;
         ++i) {
        for (size_t j = 0;
             j < n;
             j++) {
            if (j == i) {
                vect_2[i][j] = 0;
                continue;
            }
            if (local_l[j].size() + 1 < vect_2[i][j]) {
                vect_2[i][j] = inf;
                continue;
            }
        }
    }
    for (size_t i = 0;
         i < n;
         i++) {
        for (size_t j = 0;
             j < n;
             j++) {
            g[i].push_back(
                {{j, vect_2[i][j]},
                2});
        }
    }
    for (int i = 0;
         i < n;
         i++) {
        g[i].push_back(
            {{(i + 1) % (n), 1},
            1});
        g[i].push_back(
            {{(n + i - 1) % n, 1},
            0});
    }
    int now = 0;
    for (size_t i = 0;
         i < k;
         i++) {
        int id = vect_11[i] - 1;
        dx(now,
              id);
        now = id;
    }
    return 0;
}
