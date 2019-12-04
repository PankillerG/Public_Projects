#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector <float> time;
    std::vector <std::pair <float, int>> main_data(n);
    std::set <int> used_time;
    float answer;
    answer = 0;

    for (size_t i = 0; i < n; i++) {
        float temp;
        std::cin >> temp;
        time.push_back(temp);
    }

    for (size_t i = 0; i < n; i++) {
        float temp;
        std::cin >> temp;
        if (static_cast <int> (time[i]) != 0) {
            main_data[i] = {temp, static_cast<int>(time[i])};
        }
    }

    sort(main_data.rbegin(), main_data.rend());

    for (auto el : main_data) {
        if (used_time.end() != used_time.find(el.second)) {
            int temp;
            temp = el.second - 1;
            while (temp > 0 &&
                   used_time.end() != used_time.find(temp)) {
                temp--;
            }
            if (temp != 0) {
                used_time.insert(temp);
                answer = answer + el.first;
            }
        } else {
            used_time.insert(el.second);
            answer = answer + el.first;
        }
    }

    std::cout << answer;
}
