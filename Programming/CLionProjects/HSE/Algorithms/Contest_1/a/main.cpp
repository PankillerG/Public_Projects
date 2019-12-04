#include <iostream>
#include <limits>
#include <vector>


using namespace std;

int main() {
    int N, D, V, R;
    cin >> N
        >> D
        >> V
        >> R;
    vector <vector <vector <vector <int>>>> graph;
    graph.resize(N);
    for (size_t i = 0; i < N; i++) {
        graph[i].resize(N);
    }

    int number;
    number = numeric_limits<int>::max();
    vector <int> period(N);
    for (size_t i = 0; i < N; i++) {
        period[i] = number;
    }

    period[D-1] = 0;

    vector <int> willuse;

    for (size_t i = 0; i < R; i++) {
        int el0, el1, el2, el3;
        cin >> el0 >> el1 >> el2 >> el3;
        graph[el0 - 1][el2 - 1].push_back({el1, el3});
    }

    int vertex;
    vertex = D - 1;

    for (size_t v = 0; v < N; v++) {
        for (size_t t = 0; t < graph[vertex][v].size(); t++) {
            if (graph[vertex][v].size() != 0) {
                if (graph[vertex][v][t][1] < period[v]) {
                    period[v] = graph[vertex][v][t][1];
                    willuse.push_back(v);
                }
            }
        }
    }

    while (willuse.size() != 0) {
        int local;
        local = willuse[0];
        willuse.erase(willuse.begin());
        for (size_t v = 0; v < N; v++) {
            for (size_t t = 0; t < graph[local][v].size(); t++) {
                if (graph[local][v].size() != 0) {
                    if (period[local] <= graph[local][v][t][0] &&
                        period[v] > graph[local][v][t][1]) {
                            period[v] = graph[local][v][t][1];
                            willuse.push_back(v);
                    }
                }
            }
        }
    }

    if (period[V - 1] != number) {
        cout << (period[V - 1]);
    } else {
        cout << (-1);
    }

    return 0;
}
