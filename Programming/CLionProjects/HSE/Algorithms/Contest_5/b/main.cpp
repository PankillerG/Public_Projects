#include<algorithm>
#include<iostream>
#include<vector>

int main() {
    int n;
    std::cin >> n;
    std::vector <float> time;
    float local;
    for (size_t i = 0; i < n; i++) {
        std::cin >> local;
        time.push_back(local);
    }
    sort(time.begin(), time.end());
    n = 0;
    for (auto el : time) {
        if (static_cast<int>(el) - n > 0) {
            n++;
        }
    }
    std::cout << n;
}
