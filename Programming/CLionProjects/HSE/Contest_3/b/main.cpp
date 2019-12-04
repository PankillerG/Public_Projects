#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
        int x;
        int y;
        int distance;
};

bool sort_points(const Point& p1, const Point& p2) {
    return p1.distance < p2.distance;
}

int main() {
    int n;
    cin >> n;
    vector <Point> points;
    int x, y;
    points.resize(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
        points[i].distance = x * x + y * y;
    }
    sort(points.begin(), points.end(), sort_points);
    for (size_t i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }
    return 0;
}
