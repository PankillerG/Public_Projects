#include <algorithm>
#include <iostream>
#include <vector>

bool lambda(std::pair <int, int>& a,
             std::pair <int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first > a.second;
    }
}

int main() {
    int answer;
    answer = 0;
    std::vector <std::pair <int, int>> time;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        int x;
        int y;
        std::cin >> x
                 >> y;
        time.push_back({std::min(x, y),
                        std::max(x, y)});
    }
    sort(time.begin(), time.end(), lambda);
    int right_line;
    right_line = -100;
    for (auto el : time) {
        if (el.first > right_line) {
            right_line = el.second;
            answer++;
        }
    }
    std::cout << answer;
    return 0;
}
