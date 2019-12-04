#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 2003 + 228;
const int INF = 1000000000;
struct edge {
    int a, b, c, flow ;
    edge(int a, int b, int c, int flow):
        a(a), b(b), c(c), flow(flow){}
};
int dis[MAXN];
int ptr[MAXN];
vector<edge> edgelist;
vector<int> edges[MAXN];
void dinic_addedge(int a, int b, int c) {
    edges[a].push_back((int)edgelist.size());
    edgelist.push_back(edge (a, b, c, 0));
    edges[b].push_back((int)edgelist.size());
    edgelist.push_back(edge(b, a, 0, 0));
}

bool bfs_dinic(int s, int t) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty() && dis[t] == -1) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < edges[v].size(); i++) {
            int ind = edges[v][i], next = edgelist[ind].b;
            if (dis[next] == -1 && edgelist[ind].flow < edgelist[ind].c) {
                q.push(next);
                dis[next] = dis[v] + 1;
            }
        }
    }
    return dis[t] != -1;
}

int dfs_dinic(int v, int t, int flow) {
    if (!flow) {
        return 0;
    }
    if (v == t) {
        return flow;
    }
    for (; ptr[v] < (int)edges[v].size(); ptr[v]++) {
        int ind = edges[v][ ptr[v]];
        int next = edgelist[ind].b;
        if (dis[next] != dis[v] + 1) {
            continue;
        }
        int pushed = dfs_dinic(next, t, min(flow, edgelist[ind].c - edgelist[ind].flow));
        if (pushed) {
            edgelist[ind].flow += pushed;
            edgelist[ind ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic_flow(int n, int s, int t) {
    int flow = 0;
    while (true) {
        fill(dis, dis + n, -1);
        if (!bfs_dinic(s, t)) {
            break;
        }
        fill(ptr, ptr + n, 0) ;
        while (int pushed = dfs_dinic(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

map<pair<int, int>, pair<int, int> > q;


int main() {
    int n;
    cin >> n;
    int id = 0;
    for (size_t i = 0 ;i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (q[{x1, y1}] == make_pair(0, 0)) {
            q[{x1, y1}] = {id, id + 1};
            dinic_addedge(id, id + 1, 1);
            id += 2;
        }
        if (q[{x2, y2}] == make_pair(0, 0)) {
            q[{x2, y2}] = {id, id + 1};
            dinic_addedge(id, id + 1, 1);
            id += 2;
        }
        pair<int, int> ver1 = q[{x1, y1}], ver2 = q[{x2, y2}];
        dinic_addedge(ver1.second, ver2.first, 1);
        dinic_addedge(ver2.second, ver1.first, 1);
    }
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (q[{x1, y1}] == make_pair(0, 0)) {
        q[{x1, y1}] = {id, id + 1};
        dinic_addedge(id, id + 1, 1);
        id += 2;
    }
    if (q[{x2, y2}] == make_pair(0, 0)) {
        q[{x2, y2}] = {id, id + 1};
        dinic_addedge(id, id + 1, 1);
        id += 2;
    }
    pair<int, int> ver1 = q[{x1, y1}], ver2 = q[{x2, y2}];
    cout << dinic_flow(id, ver1.second, ver2.first);
    return 0;
}
