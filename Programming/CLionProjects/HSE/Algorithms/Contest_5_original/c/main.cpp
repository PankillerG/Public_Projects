#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    std::map <int, std::set <char>> map_3;
    std::map <int,
              std::vector <std::pair <char, int>>> map_2;
    std::map <int, int> map_1;

    int N;
    std::cin >> N;

    for (size_t i = 0;
         i < N;
         i++) {
        int local_1;
        int local_temp;
        std::cin >> local_1
                 >> local_temp;
        map_1[i] = local_1;
        for (size_t j = 0;
             j < local_temp;
             j++) {
            int location;
            char temp_local;
            std::cin >> temp_local
                     >> location;
            map_3[i].insert(temp_local);
            map_2[i].push_back({temp_local,
                                location});
        }
    }
    int local_temp;
    std::cin >> local_temp;
    std::cout << map_1[0]
              << "\n";
    for (size_t i = 0;
         i < local_temp;
         i++) {
        int answer;
        answer = 1;
        int position;
        position = 0;
        std::string local_w;
        std::cin >> local_w;
        for (size_t j = 0;
             j < local_w.size();
             j++) {
            if (j != 0) {
                if (position != -1) {
                    if (map_3[position].end() ==
                        map_3[position].find(local_w[j])) {
                        position = -1;
                    } else {
                        for (size_t k = 0;
                             k < map_2[position].size();
                             k++) {
                            if (local_w[j] == map_2[position][k].first) {
                                position = map_2[position][k].second;
                                k = map_2[position].size();
                            }
                        }
                    }
                }
            } else {
                if (map_3[0].end() ==
                    map_3[0].find(local_w[0])) {
                    position = -1;
                    answer = 0;
                } else {
                    for (size_t k = 0;
                         k < map_2[0].size();
                         k++) {
                        if (local_w[0] == map_2[0][k].first) {
                            position = map_2[0][k].second;
                            k = map_2[0].size();
                        }
                    }
                }
            }
        }
        std::cout << map_1[position]
                  << "\n";
    }
}
