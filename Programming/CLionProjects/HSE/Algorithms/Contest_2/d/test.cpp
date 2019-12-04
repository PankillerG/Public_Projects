#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

const int maximum_of_n = 1e3 + 1;
const int maximum_of_n_2 = maximum_of_n * 10;
int n, m;
std::vector <std::pair <int, std::pair <std::pair <int, int>, int>>> for_criskala;
std::vector <std::pair <std::pair <int, int>, int>> ways(maximum_of_n_2);
int parent[maximum_of_n];
int count_connecting_points[maximum_of_n];
std::vector <int> loc_vect;
std::vector <int> answer;
int idk[maximum_of_n][maximum_of_n_2];

void func_for_find_answer(int first,
                          int second) {
    if (idk[first][second] == 0) {
        return;
    }
    if (idk[first - 1][second] != idk[first][second]) {
        func_for_find_answer(first - 1,
                             second - ways[loc_vect[first]].second);
        answer.push_back(loc_vect[first]);
    } else {
        func_for_find_answer(first - 1,
                             second);
    }
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
        if (count_connecting_points[first] <
            count_connecting_points[second]) {
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
    std::cin >> n
        >> m;
    for (size_t i = 0;
         i < m;
         i++) {
        int x;
        int y;
        int z;
        std::cin >> x
                 >> y
                 >> z;
        x -= 1;
        y -= 1;
        ways[i] = {{x, y}, z};
        for_criskala.push_back(
            {
                z,
                {{x, y}, i}});
    }
    int p6;
    int q6;
    int p5;
    int q5;
    std::cin >> p5
             >> q5
             >> p6
             >> q6;
    sort(
        for_criskala.begin(),
        for_criskala.end());
    int all_length;
    all_length = 0;
    loc_vect.push_back(0);
    for (size_t i = 0;
         i < for_criskala.size();
         i++) {
        int x = for_criskala[i].second.first.first,
            y = for_criskala[i].second.first.second,
            id = for_criskala[i].second.second,
            len = for_criskala[i].first;
        if (find_parent(x) != find_parent(y)) {
            union_sets(x, y);
            all_length = all_length + len;
            loc_vect.push_back(id);
        }
    }
    if (loc_vect.size() != n) {
        std::cout << "Impossible";
        return 0;
    }
    int lloc;
    lloc = 0;
    if (p5 > p6) {
        lloc = q6;
    } else if (p5 < p6) {
        lloc = q5;
    } else {
        lloc = std::max(q5,
                   q6);
    }
    for (size_t i = 1;
         i < n;
         i++) {
        for (size_t j = 1;
             j <= lloc;
             j++) {
            if (j >= ways[loc_vect[i]].second) {
                idk[i][j] = std::max(
                    idk[i - 1][j],
                    idk[i - 1][j - ways[loc_vect[i]].second] +
                                   ways[loc_vect[i]].second);
            } else {
                idk[i][j] = idk[i - 1][j];
            }
        }
    }
    func_for_find_answer(n - 1,
                         lloc);
    std::map <int, int> loc_map;
    int kind_minimal = -1;
    int kind_maximal = -1;
    int minimal_sum = 0;
    int maximal_sum = 0;
    for (size_t i = 0;
         i < answer.size();
         i++) {
        minimal_sum = minimal_sum +
                      ways[answer[i]].second;
        loc_map[answer[i]]++;
    }
    for (size_t i = 1;
         i < loc_vect.size();
         i++) {
        if (loc_map[loc_vect[i]] == 0) {
            maximal_sum = maximal_sum +
                          ways[loc_vect[i]].second;
        }
    }
    int another_maximal;
    another_maximal = 0;
    if (p5 > p6) {
        another_maximal = q5;
        kind_maximal = 5;
        kind_minimal = 6;
    } else if (p5 < p6) {
        another_maximal = q6;
        kind_maximal = 6;
        kind_minimal = 5;
    } else {
        another_maximal = std::min(q5,
                                   q6);
        if (another_maximal != q5) {
            kind_maximal = 6;
            kind_minimal = 5;
        } else {
            kind_maximal = 5;
            kind_minimal = 6;
        }
    }
    if (another_maximal < maximal_sum) {
        std::cout << "Impossible";
        return 0;
    }
    int all_value;
    all_value = 0;
    if (kind_minimal != 5) {
        all_value = all_value +
                    minimal_sum * p6 +
                    maximal_sum * p5;
    } else {
        all_value = all_value +
                    minimal_sum * p5 +
                    maximal_sum * p6;
    }
    std::cout << all_value
              << "\n";
    for (size_t i = 1;
         i < loc_vect.size();
         i++) {
        if (loc_map[loc_vect[i]] != 0) {
            std::cout << loc_vect[i] + 1
                      << " "
                      << kind_minimal
                      << "\n";
        } else {
            std::cout << loc_vect[i] + 1
                      << " "
                      << kind_maximal
                      << "\n";
        }
    }
    return 0;
}
