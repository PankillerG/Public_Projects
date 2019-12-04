#include <iostream>

void heapify_down(long * graph,
                  long noda,
                  long end) {
    bool flag = false;
    long maximum_of_children;

    while ((flag == false) &&
          (noda * 2 <= end)) {
        if (noda * 2 == end) {
            maximum_of_children = noda * 2;
        } else if (graph[noda * 2 + 1] < graph[noda * 2]) {
            maximum_of_children = noda * 2;
        } else {
            maximum_of_children = 1 + noda * 2;
        }

        if (graph[maximum_of_children] <= graph[noda]) {
            flag = true;
        } else {
            long local;
            local = graph[maximum_of_children];
            graph[maximum_of_children] = graph[noda];
            graph[noda] = local;
            noda = maximum_of_children;
        }
    }
}

void heapify_sort(long * graph, long length) {
    long temp;
    temp = length / 2 - 1;

    while (temp >= 0) {
        heapify_down(graph, temp, length - 1);
        temp--;
    }

    temp = length - 1;
    while (temp >= 1) {
        long local;
        local = graph[0];
        graph[0] = graph[temp];
        graph[temp] = local;
        heapify_down(graph, 0, temp - 1);
        temp--;
    }
}

int main() {
    /*#include <cstdlib> 
    for (long i = 0;
         i < n;
         i++)
            my_array[i] = rand();
    std::cout<< "\n";
    for (long i = 0;
         i < n;
         i++)
            std::cout << my_array[i] << " ";
    std::cout << "\n\n";*/

    long n;
    std::cin >> n;

    long my_array[n];
    
    for (long i = 0;
         i < n;
         i++)
            std::cin >> my_array[i];

    heapify_sort(my_array, n);

    for (long i = 0;
         i < n;
         i++) {
            std::cout << my_array[i] << " ";
    }

    return 0;
}
