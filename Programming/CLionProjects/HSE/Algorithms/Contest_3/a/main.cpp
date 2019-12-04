#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector <int> vector_of_a;
    std::vector <std::vector <int>> sparse_data;
    int n;
    int m;
    int a_1;
    int u_1;
    int v_1;
    std::cin >> n
             >> m
             >> a_1
             >> u_1
             >> v_1;
    vector_of_a.push_back(a_1);
    for (size_t i = 1;
         i < n;
         i++) {
        auto local = (23 * vector_of_a[i-1] + 21563);
        vector_of_a.push_back(local % 16714589);
    }
    sparse_data.push_back(vector_of_a);
    for (size_t i = 1;
         pow(2, i) < n;
         i++) {
        std::vector <int> temp;
        sparse_data.push_back(temp);
        int po_1;
        po_1 = pow(2, i);
        for (size_t j = 0;
             j + po_1 <= n;
             j++) {
            int po_2;
            po_2 = pow(2, i - 1);
            sparse_data[i].push_back(
                std::min(
                    sparse_data[i-1][j],
                    sparse_data[i-1][j+ po_2]));
        }
    }

    int up;
    int low;
    int answer;
    int low_local;
    int up_local;

    low = u_1;
    up = v_1;

        if (low >= up) {
            low_local = up;
            up_local = low;
        } else {
            low_local = low;
            up_local = up;
        }
        int temp;
        temp = static_cast <int> (log2(up_local - low_local + 1));
        answer = (std::min(
            sparse_data[temp][low_local - 1],
            sparse_data[temp][up_local - pow(2, temp)]));
    for (size_t i = 0;
         i < m;
         i++) {
        int low_local;
        int up_local;
        if (low >= up) {
            low_local = up;
            up_local = low;
        } else {
            low_local = low;
            up_local = up;
        }
        int temp;
        temp = static_cast <int> (log2(up_local - low_local + 1));
        answer = (std::min(
            sparse_data[temp][low_local - 1],
            sparse_data[temp][up_local - pow(2, temp)]));
        if (m - 1 != i) {
            auto temp_l = 17 * low + 751 + answer + 2 * (i + 1);
            low = temp_l % n + 1;
            auto temp_u = 13 * up + 593 + answer + 5 * (i + 1);
            up = temp_u % n + 1;
        }
    }
    std::cout << low
              << " "
              << up
              << " "
              << answer
              << "\n";
}
