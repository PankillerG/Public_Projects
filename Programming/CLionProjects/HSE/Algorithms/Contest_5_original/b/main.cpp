#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::vector <std::vector <long>> main_data;
    int K;
    std::cin >> K;
    main_data.resize(K + 1);

    for (int c_1 = 0;
         c_1 < K + 1;
         c_1++) {
        for (int c_2 = 0;
             c_2 < K + 1;
             c_2++) {
            main_data[c_1].push_back(0);
        }
    }

    for (int c_1 = 1;
         c_1 < K + 1;
         c_1++) {
        for (int c_2 = 1;
             c_2 < K + 1;
             c_2++) {
            std::cin >> main_data[c_1][c_2];
        }
    }

    std::vector <long> vect_1;
    vect_1.resize(K + 1);
    std::vector <long> vect_2;
    vect_2.resize(K + 1);
    std::vector <long> vect_3;
    vect_3.resize(K + 1);
    std::vector <long> vect_4;
    vect_4.resize(K + 1);

    for (int i = 1;
         i <= K;
         i++) {
        long local_j = 0;
        vect_3[0] = i;

        std::vector <long long> data_minimal;
        std::vector <char> data_of_using;

        data_minimal.resize(K + 1, 20000);
        data_of_using.resize(K + 1, false);

        while (vect_3[local_j] != 0) {
            long delta = 20000;
            long local_j_1;
            data_of_using[local_j] = true;
            for (int j = 1;
                 j <= K;
                 j++) {
                if (data_of_using[j] == false) {
                    long this_is_step;
                    this_is_step = main_data[vect_3[local_j]][j] -
                           vect_1[vect_3[local_j]] -
                           vect_2[j];
                    if (data_minimal[j] > this_is_step) {
                        data_minimal[j] = this_is_step;
                        vect_4[j] = local_j;
                    }
                    if (delta > data_minimal[j]) {
                        delta = data_minimal[j];
                        local_j_1 = j;
                    }
                }
            }
            for (int j = 0;
                 j <= K;
                 j++) {
                if (data_of_using[j] == false) {
                    data_minimal[j] = data_minimal[j] - delta;
                } else {
                    vect_1[vect_3[j]] = vect_1[vect_3[j]] + delta;
                    vect_2[j] = vect_2[j] - delta;
                }
            }
            local_j = local_j_1;
        }
        while (local_j) {
            int local_j_1;
            local_j_1 = vect_4[local_j];
            vect_3[local_j] = vect_3[local_j_1];
            local_j = local_j_1;
        }
    }
    long long answer;
    answer = 0;
    for (int i = 1;
         i <= K;
         i++)
        answer = answer + main_data[vect_3[i]][i];
    std::cout << answer
              << "\n";
    return 0;
}
