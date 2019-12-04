#include <iostream>
#include <vector>

void heapify(std::vector <int>& graph,
             size_t len,
             size_t el) {
    size_t left;
    left = 2 * el + 1;
    size_t right;
    right = 2 * el + 2;
    size_t maximum;
    maximum = el;
    if (len > left &&
        graph[maximum] > graph[left]) {
            maximum = left;
    }
    if (len > right &&
        graph[maximum] > graph[right]) {
            maximum = right;
    }
    if (maximum != el) {
        int temp;
        temp = graph[el];
        graph[el] = graph[maximum];
        graph[maximum] = temp;
        heapify(graph, len, maximum);
    }
}

int heap_out(std::vector <int>& graph,
             size_t len) {
    int max_elem;
    max_elem = graph[0];

    graph[0] = graph[len - 1];
    len -= 1;

    graph.pop_back();

    heapify(graph, len, 0);
    return max_elem;
}


int main() {
    std::vector <int> a;

    int n;
    std::cin >> n;

    a.resize(n);
    for (size_t i = 0;
         i < n;
         i++) {
            std::cin >> a[i];
    }

    size_t len_;
    len_ = a.size();
    size_t temp = len_ / 2 -1;
    while (temp != (size_t)(-1)) {
        heapify(a, len_, temp);
        temp--;
    }

    for (size_t i = 0;
         i < n;
         i++) {
            std::cout << heap_out(a, a.size()) << " ";
    }
}
