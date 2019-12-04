#include <algorithm>
#include <iostream>

void heapify(int my_aaray[],
             int noda,
             int el) {
    int left;
    left = 2 * el + 1;
    int right;
    right = 2 * el + 2;
    int maximum = el;

    if (my_aaray[left] > my_aaray[maximum] &&
        left < noda)
        maximum = left;
    if (my_aaray[right] > my_aaray[maximum] &&
        right < noda)
        maximum = right;
    if (maximum != el) {
        int temp;
        temp = my_aaray[el];
        my_aaray[el] = my_aaray[maximum];
        my_aaray[maximum] = temp;
        heapify(my_aaray, noda, maximum);
    }
}


void heapSort(int my_aaray[], int n) {
    int temp;
    temp = n / 2 - 1;
    while (temp >= 0) {
        heapify(my_aaray, n, temp);
        temp--;
    }

    temp = n - 1;
    while (temp >= 0) {
        int local;
        local = my_aaray[0];
        my_aaray[0] = my_aaray[temp];
        my_aaray[temp] = local;

        heapify(my_aaray, temp, 0);

        temp--;
    }
}

int main() {
    int n;
    std::cin >> n;
    int my_aaray[n];

    for (long i = 0;
         i < n;
         i++)
            std::cin >> my_aaray[i];

    heapSort(my_aaray, n);

    for (size_t i = 0;
         i < n;
         i++)
            std::cout << my_aaray[i]
                      << " ";
}
