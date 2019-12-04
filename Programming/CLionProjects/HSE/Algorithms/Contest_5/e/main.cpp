#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

bool lambda(const std::pair <int, int>& a, const std::pair <int, int>& b) {
    int other_part_a;
    int other_part_b;
    other_part_a = std::max(a.second, b.first + b.second);
    other_part_b = std::max(b.second, a.first + a.second);
    if (a.first + other_part_a < b.first + other_part_b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    std::cin >> n;
    long long answer;
    long long time_for_download;
    answer = 0;
    time_for_download = 0;
    std::vector <std::pair <int, int>> vector_values;
    vector_values.resize(n);
    for (size_t i = 0; i < n; i++) {
        int temp1;
        int temp2;
        std::cin >> temp1 >> temp2;
        vector_values[i].first = temp1;
        vector_values[i].second = temp2;
    }
    sort(vector_values.begin(), vector_values.end(), lambda);
    for (size_t i = 0; i < n; i++) {
        time_for_download = time_for_download + vector_values[i].first;
        answer = std::max(time_for_download + vector_values[i].second, answer);
    }
    std::cout << answer;
    return 0;
}
