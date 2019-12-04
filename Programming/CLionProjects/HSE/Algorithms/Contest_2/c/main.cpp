#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

const int maximum_of_n = 51;
int n, m;
std::vector <std::pair <double, double>> ways(maximum_of_n);
std::vector <std::pair <double, std::pair <double, double>>> for_cruskala;
int parent[maximum_of_n];
int count_connecting_points[maximum_of_n];
std::map <std::pair <double, double>, int> local;

double dist(std::pair <double, double> x,
            std::pair <double, double> y) {
    return sqrt(((x.first - y.first) * (x.first - y.first)) +
                ((x.second - y.second) * (x.second - y.second)));
}

int find_parent(int point) {
    if (point != parent[point]) {
        return parent[point] = find_parent(parent[point]);
    } else {
        return point;
    }
}

void union_sets(int first,
                int second) {
    first = find_parent(first);
    second = find_parent(second);
    if (first != second) {
        if (count_connecting_points[first] < count_connecting_points[second]) {
            std::swap(first, second);
        }
        parent[second] = first;
        if (count_connecting_points[first] ==
            count_connecting_points[second]) {
                count_connecting_points[first] += 1;
        }
    } else {
        return;
    }
}

int main() {
    for (size_t i = 0;
         i < maximum_of_n;
         i++) {
        parent[i] = i;
        count_connecting_points[i] = 1;
    }
    std::cin >> n;
    for (int i = 0;
         i < n;
         i++) {
        std::cin >> ways[i].first
                 >> ways[i].second;
    }
    std::cin >> m;
    for (size_t i = 0;
         i < m;
         i++) {
        int x, y;
        std::cin >> x
                 >> y;
        x -= 1;
        y -= 1;
        local[{std::min(x, y),
               std::max(y, x)}] += 1;
        for_cruskala.push_back(
            {
                0.0,
                {
                    std::min(x, y),
                    std::max(y, x)}});
    }
    for (size_t i = 0;
         i < n - 1;
         i++) {
        for (size_t j = i + 1;
             j < n;
             j++) {
            if (local[{i, j}] == 0) {
                for_cruskala.push_back(
                    {dist(
                        ways[i],
                        ways[j]),
                        {i, j}});
            }
        }
    }
    std::sort(for_cruskala.begin(),
              for_cruskala.end());
    double answer = 0;
    for (size_t i = 0;
         i < for_cruskala.size();
         i++) {
        double x = for_cruskala[i].second.first,
               y = for_cruskala[i].second.second,
               length_ = for_cruskala[i].first;
        if (find_parent(x) != find_parent(y)) {
            answer = answer + length_;
            union_sets(x, y);
        }
    }
    std::cout << std::setprecision(6)
              << std::fixed
              << answer;
    return 0;
}

