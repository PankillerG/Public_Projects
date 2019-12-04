#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int dj(int vertex,
       int some,
       vector <int>& willuse,
       int n,
       vector <vector <vector<int>>>& weight,
       vector <vector <vector<int>>>& graph) {
    int number;
    number = numeric_limits <int>::max();
    vector <int> period(n, number);

    for (size_t v = 0; v < n; v++) {
        if (vertex != v && graph[vertex][v].size() != 0 && some <= weight[vertex][v][0]) {
            period[v] = graph[vertex][v][0];
            willuse.push_back(v);
        }
    }

    while (willuse.size() != 0) {
        int local;
        local = willuse[0];
        willuse.erase(willuse.begin());

        for (size_t v = 0; v < n; v++) {
            if (local != v &&
                graph[local][v].size() != 0 &&
                some <= weight[local][v][0] &&
                graph[local][v][0] <= 1440 - period[local] &&
                graph[local][v][0] < period[v] - period[local]) {
                    period[v] = graph[local][v][0] + period[local];
                    willuse.push_back(v);
            }
        }
    }

    if (1440 < period[n - 1]) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector <vector<int>>> graph;
    graph.resize(n);
    vector <vector < vector <int>>> weight;
    weight.resize(n);
    for (size_t i = 0; i < n; i++) {
        graph[i].resize(n);
        weight[i].resize(n);
    }
    vector <int> willuse;

    int all = 0;

    vector <int> local;
    vector <int> temp;
    vector <int> temp2;
    vector <int> period;

    if (m == 0) {
        cout << 10000000;
    } else {
        int number;
        number = numeric_limits <int>::max();

        for (size_t i = 0; i < m; i++) {
            int el0, el1, el2, el3;
            cin >> el0 >> el1 >> el2 >> el3;
            if (1440 >= el2) {
                temp.push_back(el3);
            }
            graph[el0 - 1][el1 - 1].push_back(el2);
            weight[el0 - 1][el1 - 1].push_back(el3);
            graph[el1 - 1][el0 - 1].push_back(el2);
            weight[el1 - 1][el0 - 1].push_back(el3);
        }

        //
        temp2 = temp;
        //
        sort(temp2.begin(), temp2.end());
        int all;

        int first = 0, last;
        last = temp2.size() - 1;
        int mid;
        mid = last + first;
        mid /= 2;
        while (last >= first) {
            mid = last + first;
            mid /= 2;
            if (dj(0, temp2[mid], willuse, n, weight, graph) == 0) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        if (dj(0, temp2[last], willuse, n, weight, graph) == 0) {
            all = temp2[first];
        } else {
            all = temp2[last];
        }
    }

    int answer;
    if (dj(0, all, willuse, n, weight, graph) == 1 &&
        3000000 < all) {
            answer = all - 3000000;
            answer /= 100;
            cout << answer;
    } else {
        cout << 0;
    }
    return 0;
}
