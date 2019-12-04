#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int K;
  cin >> K;
  vector<vector<long>> tasks(K + 1);
  for (int i = 0; i < K + 1; ++i) {
    for (int j = 0; j < K + 1; ++j) {
      tasks[i].push_back(0);
    }
  }
  for (int i = 1; i < K + 1; ++i) {
    for (int j = 1; j < K + 1; ++j) {
      cin >> tasks[i][j];
    }
  }
  vector<long> u(K + 1), v(K + 1), p(K + 1), way(K + 1);
  for (int i = 1; i <= K; ++i) {
    p[0] = i;
    long j0 = 0;
    vector<long long> minimals(K + 1, 20000);
    vector<char> used(K + 1, false);
    while (p[j0] != 0) {
      used[j0] = true;
      long delta = 20000, j1;
      for (int j = 1; j <= K; ++j) {
        if (!used[j]) {
          long step = tasks[p[j0]][j] - u[p[j0]] - v[j];
          if (step < minimals[j]) {
            minimals[j] = step;
            way[j] = j0;
          }
          if (minimals[j] < delta) {
            delta = minimals[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= K; ++j) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        }
        else {
          minimals[j] -= delta;
        }
      }
      j0 = j1;
    }
    while (j0) {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    }
  }
  long long result = 0;
  for (int i = 1; i <= K; ++i)
    result += tasks[p[i]][i];
  cout << result << "\n";
  return 0;
}