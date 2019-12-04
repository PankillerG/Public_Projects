#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long my_array[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> my_array[i];
    }

    int step = 0;
    int temp;
    bool flag;

    while (step + 2 < n) {
        flag = false;
        for (int i = 0; i < n; i++) {
            if (i * 2 + 2 + step < n) {
                if ((my_array[i + step] > my_array[i * 2 + step + 2]) ||
                    (my_array[i + step] > my_array[i * 2 + step + 1])) {
                        if (my_array[i * 2 + step + 1] > my_array[i * 2 + step + 2]) {
                            flag = true;
                            temp = my_array[i + step];
                            my_array[i + step] = my_array[i * 2 + step + 2];
                            my_array[i * 2 + step + 2] = temp;
                        } else if (my_array[i * 2 + step + 2] > my_array[i * 2 + step + 1]) {
                            flag = true;
                            temp = my_array[i + step];
                            my_array[i + step] = my_array[i * 2 + step + 1];
                            my_array[i * 2 + step + 1] = temp;
                        }
                }

                if (my_array[i * 2 + step + 1] > my_array[i * 2 + step + 2]) {
                    flag = true;
                    temp = my_array[i * 2 + 1 + step];
                    my_array[i * 2 + 1 + step] = my_array[i * 2 + step + 2];
                    my_array[i * 2 + step + 2] = temp;
                }
            } else if (i * 2 + step + 1 < n) {
                if (my_array[i + step] > my_array[ i * 2 + step + 1]) {
                    flag = true;
                    temp = my_array[i + step];
                    my_array[i + step] = my_array[i * 2 + step + 1];
                    my_array[i * 2 + step + 1] = temp;
                }
            }
        }

        if (flag == false)
            ++step;
    }
    
    for (int i = 0; i < n; i++)
        std::cout << my_array[i]
                  << " ";

    return 0;
}
