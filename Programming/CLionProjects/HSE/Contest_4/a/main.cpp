#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long local;
    vector <long long> points;
    while (cin >> local) {
        points.push_back(local);
    }
    sort(
        points.begin(),
        points.end(),
        [n](const auto& p1, const auto& p2) {
            return make_tuple(abs(n - p1), p1) < make_tuple(abs(n - p2), p2);
        });
    for (size_t i = 0; i < points.size(); i++) {
        cout << points[i] << "\n";
    }
    return 0;
}
