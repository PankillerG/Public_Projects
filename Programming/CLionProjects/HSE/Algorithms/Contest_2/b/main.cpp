#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

const int maximum_of_n = 1e5 + 1;
int n, m;
std::set <int> main_points;
int parent[maximum_of_n];
int count_connecting_points[maximum_of_n];

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
        if (first > second) {
            std::swap(first, second);
        }
        parent[second] = first;
        count_connecting_points[first] = count_connecting_points[first] +
                                         count_connecting_points[second];
    } else {
        return;
    }
}

int main() {
    std::cin >> n
             >> m;
    for (size_t i = 0;
         i < n;
         i++) {
        main_points.insert(i);
    }
    for (size_t i = 0;
         i < maximum_of_n;
         i++) {
        parent[i] = i;
        count_connecting_points[i] = 1;
    }
    char ch;
    for (size_t i = 0;
         i < m;
         i++) {
        std::cin >> ch;
        if (ch == 'a') {
            int first, second;
            std::cin >> first
                     >> second;
            first -= 1;
            second -= 1;
            first = find_parent(first);
            second = find_parent(second);
            if (first == second) {
                continue;
            }
            auto temp1 = count_connecting_points[first] % 2;
            auto temp2 = count_connecting_points[second] % 2;
            union_sets(first,
                       second);
            if (temp1 == 1 &&
                temp2 == 1) {
                    main_points.erase(first);
                    main_points.erase(second);
            } else if (temp1 == 1 &&
                       temp2 == 0) {
                if (parent[first] == second) {
                    main_points.insert(second);
                    main_points.erase(first);
                }
            } else if (temp1 == 0 &&
                       temp2 == 1) {
                if (parent[second] == first) {
                    main_points.insert(first);
                    main_points.erase(second);
                }
            }
        } else {
            if (main_points.size() != 0) {
                auto temp = *main_points.begin();
                std::cout << temp + 1
                          << "\n";
            } else {
                std::cout << -1
                          << "\n";
            }
        }
    }
    return 0;
}
