#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 228;
const int inf = 1e9;

int n, k;

long long d[maxn][maxn];
long long dis[maxn][maxn];
long long common[maxn][maxn];
vector<int> b(maxn);

const long long p = 29;
const long long q = 1e9 + 7;

int f_pre(int i, int j, int mx) {
    int l = 0;
    int r = mx - 1;
    int mid = 1;
    while (r >= l) {
        mid = (l + r) / 2;
        if (d[i][mid + 1] == d[j][mid + 1] && mid + 1 < mx) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (d[i][l] != d[j][l]) {
        return 0;
    }
    return l + 1;
}

vector <string> a(maxn);
vector <pair <pair <int, int>, int>> g[maxn];

void dxtra(int s, int en) {
    vector<int> di(n, inf);
    vector <pair<int, int>> p(n);
    di[s]= 0;
    vector<char> u(n);
    for (size_t i = 0; i < n; ++i) {
        int v = -1;
        for (size_t j = 0; j < n; j++)
            if (!u[j] && (v == -1 || di[j] < di[v]))
                v = j;
        if (di[v] == inf)
            break;
        u[v]= true;

        for (size_t j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first.first,
                len = g[v][j].first.second;
            int na = g[v][j].second;
            if (di[v] + len < di[to]) {
                di[to] = di[v] + len;
                p[to]= {v, na};
            }
        }
    }

    cout << di[en] << endl;

    int x = en;
    vector <int> ans;
    vector <int> ver;
    ver.push_back(en);
    while (p[x].first != s) {
        ans.push_back(p[x].second);
        ver.push_back(p[x].first);
        x = p[x].first;
    }
    ans.push_back(p[x].second);
    ver.push_back(p[x].first);
    reverse(ans.begin(), ans.end());
    reverse(ver.begin(), ver.end());

    for (size_t i = 0; i < ver.size() - 1; ++i) {
        if (ans[i] == 0) {
            cout << "up\n";
        } else if (ans[i] == 1) {
            cout << "down\n";
        } else {
            cout << "Alt\n";
        }
        if (ans[i] == 2) {
            for (size_t j = 0; j < dis[ver[i]][ver[i + 1]] - 1; j++) {
                cout << a[ver[i + 1]][j] << "\n";
            }
        }
    }
}

int main() {
    for (size_t i = 0; i < maxn; ++i) {
        for (size_t j = 0; j < maxn; ++j) {
            d[i][j]= inf;
            dis[i][j] = inf;
            common[i][j] = inf;
        }
    }
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
        common[i][i] = 0;
    }
    cin >> k;
    for (size_t i = 0; i < k; ++i) {
        cin >> b[i];
    }

    for (size_t i = 0; i < n; ++i) {
        long long hash = 0;
        for (size_t j = 0; j < a[i].size(); ++i) {
            d[i][j] = (hash * p + (a[i][j] - 'a' + 1)) % q;
            hash = d[i][j];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            common[i][j]= f_pre(i, j, min(a[i].size(), a[j].size()));
        }
        for (size_t j = 0; j < i; j++) {
            common[i][j] = f_pre(i, j, min(a[i].size(), a[j].size()));
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (i == 0) {
            dis[n - 1][i] = common[n - 1][i] + 2;
        } else {
            dis[i - 1][i] = common[i - 1][i] + 2;
        }
        for (int j = 2; j < n; j++) {
            dis[(n + i - j) % n][i] = max(common[(n + i - j) % n][i] + 2,
                                          dis[(n + i - j + 1) % n][i]);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; j++) {
            if (i == j) {
                dis[i][j] = 0;
                continue;
            }
            if (a[j].size() + 1 < dis[i][j]) {
                dis[i][j] = inf;
                continue;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            g[i].push_back({{j, dis[i][j]}, 2});
        }
    }

    for (int i = 0; i < n; i++) {
        g[i].push_back({{(i + 1) % n, 1}, 1});
        g[i].push_back({{(n + i - 1) % n, 1}, 0});
    }
    int cur = 0;
    for (size_t i = 0; i < k; i++) {
        int id = b[i] - 1;
        dxtra(cur, id);
        cur = id;
    }
    return 0;
}



