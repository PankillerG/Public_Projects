#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

const int maximum_of_n = 2003 + 1;
int local_2[maximum_of_n];
int local_1[maximum_of_n];
const int bigbigbig = 1000000000;
std::map< std::pair <int, int>,
          std::pair <int, int>> main_map;

struct my_struct {
    int temp_1;
    int temp_2;
    int temp_3;
    int temp_4;
    my_struct(int temp_1,
              int temp_2,
              int temp_3,
              int temp_4):
        temp_1(temp_1),
        temp_2(temp_2),
        temp_3(temp_3),
        temp_4(temp_4){}
};
std::vector <int> array_for_struct[maximum_of_n];
std::vector <my_struct> list_of_struct;

void my_func_1(int temp_1,
                   int temp_2,
                   int temp_3) {
    array_for_struct[temp_1].push_back(
        static_cast <int> (
            list_of_struct.size()));
    list_of_struct.push_back(
        my_struct(temp_1,
                  temp_2,
                  temp_3,
                  0));
    array_for_struct[temp_2].push_back(
        static_cast <int> (
            list_of_struct.size()));
    list_of_struct.push_back(
        my_struct(temp_2,
                  temp_1,
                  0,
                  0));
}

bool my_func_2(int one,
               int two) {
    std::queue <int> my_queue;
    my_queue.push(one);
    local_1[one] = 0;
    while (!my_queue.empty() &&
           local_1[two] == -1) {
        int temp_;
        temp_ = my_queue.front();
        my_queue.pop();
        for (int i = 0;
             i < array_for_struct[temp_].size();
             i++) {
            int locat_1;
            locat_1 = array_for_struct[temp_][i];
            int locat_2;
            locat_2 = list_of_struct[locat_1].temp_2;
            if (local_1[locat_2] == -1 &&
                list_of_struct[locat_1].temp_3 > list_of_struct[locat_1].temp_4) {
                my_queue.push(locat_2);
                local_1[locat_2] = 1 + local_1[temp_];
            }
        }
    }
    if (local_1[two] != -1) {
        return true;
    } else {
        return false;
    }
}
int my_func_3(int one,
              int two,
              int temp_4) {
    if (temp_4) {
        if (one != two) {
            for (;
                 local_2[one] < static_cast <int> (array_for_struct[one].size());
                 local_2[one]++) {
                int locat_1;
                locat_1 = array_for_struct[one][ local_2[one]];
                int locat_2;
                locat_2 = list_of_struct[locat_1].temp_2;
                if (local_1[one] + 1 != local_1[locat_2]) {
                    continue;
                }
                int pushed;
                pushed = my_func_3(locat_2,
                                   two,
                                   std::min(
                                       temp_4,
                                       list_of_struct[locat_1].temp_3 -
                                        list_of_struct[locat_1].temp_4));
                if (pushed) {
                    list_of_struct[locat_1].temp_4 = list_of_struct[locat_1].temp_4 +
                                                     pushed;
                    list_of_struct[locat_1 ^ 1].temp_4 = list_of_struct[locat_1 ^ 1].temp_4  -
                                                         pushed;
                    return pushed;
                }
            }
            return 0;
        } else {
            return temp_4;
        }
    } else {
        return 0;
    }
}
int my_func_4(int one,
               int two,
               int three) {
    int temp_4;
    temp_4 = 0;
    while (1 == 1) {
        std::fill(local_1,
                  local_1 + one,
                  -1);
        if (!my_func_2(two,
                       three)) {
            break;
        }
        std::fill(local_2,
                  local_2 + one,
                  0);
        while (int pushed = my_func_3(two,
                                      three,
                                      bigbigbig)) {
            temp_4 = temp_4 +
                     pushed;
        }
    }
    return temp_4;
}
int main() {
    int n;
    int identifier;
    identifier = 0;
    std::cin >> n;
    for (size_t i = 0;
         i < n;
         i++) {
        int p_1_1;
        int p_1_2;
        int p_2_1;
        int p_2_2;
        std::cin >> p_1_1
                 >> p_1_2
                 >> p_2_1
                 >> p_2_2;
        if (main_map[{p_1_1,
                      p_1_2}] == std::make_pair(0,
                                                0)) {
            main_map[{p_1_1,
                      p_1_2}] = {identifier,
                                 identifier + 1};
            my_func_1(identifier,
                          identifier + 1,
                          1);
            identifier = identifier + 2;
        }
        if (main_map[{p_2_1,
                      p_2_2}] == std::make_pair(0,
                                                0)) {
            main_map[{p_2_1,
                      p_2_2}] = {identifier,
                                 identifier + 1};
            my_func_1(identifier,
                          identifier + 1,
                          1);
            identifier = identifier + 2;
        }
        std::pair <int,
                   int> tempror_1 = main_map[{p_1_1,
                                              p_1_2}];
        std::pair <int,
                   int> tempror_2 = main_map[{p_2_1,
                                              p_2_2}];
        my_func_1(tempror_1.second,
                      tempror_2.first,
                      1);
        my_func_1(tempror_2.second,
                      tempror_1.first,
                      1);
    }
    long long p_1_1;
    long long p_1_2;
    long long p_2_1;
    long long p_2_2;
    std::cin >> p_1_1
             >> p_1_2
             >> p_2_1
             >> p_2_2;
    if (main_map[{p_1_1,
                  p_1_2}] == std::make_pair(0,
                                            0)) {
        main_map[{p_1_1,
                  p_1_2}] = {identifier,
                             identifier + 1};
        my_func_1(identifier,
                      identifier + 1,
                      1);
        identifier = identifier + -2;
    }
    if (main_map[{p_2_1,
                  p_2_2}] == std::make_pair(0,
                                            0)) {
        main_map[{p_2_1,
                  p_2_2}] = {identifier,
                             identifier + 1};
        my_func_1(identifier,
                      identifier + 1,
                      1);
        identifier = identifier + 2;
    }
    std::pair<int, int> tempror_1;
    tempror_1 = main_map[{p_1_1,
                     p_1_2}];
    std::pair<int, int> tempror_2;
    tempror_2 = main_map[{p_2_1,
                     p_2_2}];
    std::cout << my_func_4(identifier,
                            tempror_1.second,
                            tempror_2.first);
    return 0;
}
