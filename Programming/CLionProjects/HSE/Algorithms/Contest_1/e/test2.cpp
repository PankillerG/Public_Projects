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

    if (graph[maximum] > graph[left] &&
        len > left) {
            maximum = left;
    }
    if (graph[maximum] > graph[right] &&
        len > right)
            maximum = right;
    if (maximum != el) {
        int temp;
        temp = graph[el];
        graph[el] = graph[maximum];
        graph[maximum] = temp;
        heapify(graph, len, maximum);
    }
}

/*void Heapsort(std::vector<int>& graph) {
    size_t temp;
    temp = graph.size() / 2 - 1;
    while (temp != (size_t)(-1)) {
        heapify(graph, graph.size(), temp);
    }

    for (size_t i = graph.size() - 1; i > 0; i--) {
        std::swap(graph[0], graph[i]);
        heapify(graph, i, 0);
    }
}

void Heap_Increase_Key(std::vector<int>& graph, size_t len, size_t i, int key) {
    graph[i] = key;
    while (i > 0 && graph[(i-1)/2] > graph[i]) {
        std::swap(graph[(i-1)/2], graph[i]);
        i = (i-1)/2;
    }
}

void Heap_Insert(std::vector<int>& graph, size_t len, int key) {
    len++;
    if (len > graph.size())
        graph.resize(len);
    Heap_Increase_Key(graph, len, len - 1, key);
}*/

int heap_out(std::vector <int>& graph,
             size_t len) {
    int max_el;
    max_el = graph[0];

    graph[0] = graph[len - 1];
    len -= 1;

    graph.pop_back();
    heapify(graph, len, 0);

    return max_el;
}


int main() {
    int n;
    std::cin >> n;

    std::vector <int> my_array(n);
    for (size_t i = 0;
         i < n;
         i++) {
            std::cin >> my_array[i];
    }

    size_t temp;
    temp = my_array.size() / 2 - 1;
    size_t local;
    local = my_array.size();
    while (temp != (size_t)(-1)) {
        heapify(my_array, local, temp);
        temp--;
    }

    for (size_t i = 0;
         i < n;
         i++) {
            std::cout << heap_out(my_array, my_array.size())
                      << " ";
    }
    return 0;
}

