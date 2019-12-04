#include <iostream>

const int maximum_of_n = 1e5 + 1;
int parent[maximum_of_n];

int find_parent(int point) {
    if (point != parent[point]) {
        return parent[point] = find_parent(parent[point]);
    } else {
        return point;
    }
}

void union_sets(int first,
                int second) {
    first = find_parent(first);
    second = find_parent(second);
    if (first != second) {
        parent[second] = first;
    } else {
        return;
    }
}


int main() {
    int n, m;
    std::cin >> n
             >> m;
    for (size_t i = 0;
         i < maximum_of_n;
         i++) {
        parent[i] = i;
    }
    for (size_t i = 0 ;
         i < m;
         i++) {
        char ch;
        std::cin >> ch;
        if (ch == 'b') {
            int temp;
            std::cin >> temp;
            std::cout << find_parent(temp)
                      << "\n";
        } else {
            int first, second;
            std::cin >> first
                     >> second;
            union_sets(find_parent(first),
                       find_parent(second));
         }
    }
    return 0;
}
