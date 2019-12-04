#include<algorithm>
#include<iomanip>
#include<iostream>
#include<vector>

bool lambda(const std::pair <double, long long>& a,
            const std::pair <double, long long>& b) {return a.first > b.first;}

int main() {
    long long N;
    long long W;
    long long p;
    long long w;
    double kpd;
    std::cin >> N
             >> W;
    long long weight_limit;
    weight_limit = W;
    double answer;
    std::vector <std::pair <double, long long>> all;
    answer = 0;
    for (size_t i = 0; i < N; i++) {
        std::cin >> p
                 >> w;
        if (w == 0) {
            answer += p;
        } else {
            kpd = p / static_cast <double>(w);
        }
        all.push_back({kpd, w});
    }
    sort(all.begin(), all.end(), lambda);
    for (auto el : all) {
        if (el.second > weight_limit) {
            answer += el.first * weight_limit;
            weight_limit = 0;
            break;
        } else {
            answer += el.first * el.second;
            weight_limit -= el.second;
        }
    }
    std::cout << std::fixed
              << std::setprecision(6)
              << answer;
}
