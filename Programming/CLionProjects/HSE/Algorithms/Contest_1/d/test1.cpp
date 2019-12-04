#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <vector>

class my_heap {
 private:
    std::vector <std::pair <int, int>> graph_data;

 public:
    my_heap() {}
    my_heap(int num) {
        graph_data.resize(num);
    }

    void heapify(int parent) {
        bool flag = true;
        while (flag) {
            int left;
            left = 2 * parent + 1;
            int right;
            right = 2 * parent + 2;
            int minimum;
            minimum = graph_data[parent].second;
            int child_minimum;
            child_minimum = left;
            int temp;
            temp = graph_data.size() - 1;
            if (left <= temp &&
                minimum > graph_data[left].second) {
                    minimum = graph_data[left].second;
                    child_minimum = left;
            }
            if (right <= temp &&
                minimum > graph_data[right].second) {
                    minimum = graph_data[right].second;
                    child_minimum = right;
            }
            if (minimum != graph_data[parent].second) {
                std::swap(graph_data[parent],
                          graph_data[child_minimum]);
                parent = child_minimum;
            } else {
                flag = false;
            }
        }
    }

    void build_heap(std::vector <std::pair <int, int>>& source) {
        size_t i;
        i = 0;
        while (i < source.size()) {
            graph_data[i] = source[i];
            i++;
        }
        int j;
        j = graph_data.size() / 2;
        while (j >= 0) {
            heapify(j);
            j--;
        }
    }

    void insert(std::pair <int, int> number) {
        graph_data.push_back(number);
        int id;
        id = graph_data.size() - 1;
        int before;
        before = (id - 1) / 2;
        while (id > 0 &&
               graph_data[id].second < graph_data[number.first].second) {
            std::swap(graph_data[id],
                      graph_data[number.first]);
            id = number.first;
            int temp;
            temp  = (id - 1) / 2;
            number.first = temp;
        }
    }

    std::pair <int, int> min_out() {
        std::pair <int, int> answer = graph_data[0];
        int temp;
        temp = graph_data.size() - 1;
        graph_data[0] = graph_data[temp];
        graph_data.pop_back();
        temp = graph_data.size();
        if (temp != 0) {
            heapify(0);
        }
        return answer;
    }

    void DecreaseKey(std::pair <int, int> change) {
        for (int i = 0;
             i < graph_data.size();
             i++) {
            if (change.first == graph_data[i].first) {
                if (graph_data[i].second > change.second) {
                    graph_data[i].second = change.second;
                    while (i >= 0 &&
                           graph_data[i].second > graph_data[(i-1)/2].second) {
                        std::swap(graph_data[i],
                                  graph_data[(i-1)/2]);
                        i = (i-1) / 2;
                    }
                    int j;
                    j = graph_data.size() / 2;
                    while (j >= 0) {
                        heapify(j);
                        j--;
                    }
                    break;
                }
            }
        }
    }

    size_t size() {
        return graph_data.size();
    }
};


int main() {
    int n, m;
    std::cin >> n
             >> m;
    std::vector <std::vector <std::pair <int, int>>> in_list(n);
    for (size_t i = 0;
         i < m;
         i++) {
        int point1;
        int point2;
        int len_;
        std::cin >> point1
                 >> point2
                 >> len_;
        int point1_1;
        point1_1 = point1 - 1;
        int point2_2;
        point2_2 = point2 - 1;
        in_list[point1_1].push_back(
            std::make_pair(
                point2_2,
                len_));
        in_list[point2_2].push_back(
            std::make_pair(
                point1_1,
                len_));
    }
    int count;
    count = 0;
    std::set <int> points_not_used;
    for (int i = 0;
         i < n;
         i++) {
        points_not_used.insert(i);
    }
    my_heap queue(n - 1);
    std::set <int> points_used;
    points_used.insert(0);
    points_not_used.erase(0);
    std::vector <std::pair <int, int>> loc_vect;
    for (int i = 1;
         i < n;
         i++) {
        loc_vect.push_back(
            std::make_pair(
                i,
                std::numeric_limits<int>::max()));
    }
    for (auto el : in_list[0]) {
        loc_vect[el.first - 1] = el;
    }
    queue.build_heap(loc_vect);
    while (queue.size() != 0) {
        auto c = queue.min_out();
        count = count + c.second;
        points_used.insert(c.first);
        points_not_used.erase(c.first);
        for (auto el : in_list[c.first]) {
            if (points_not_used.end() !=
                points_not_used.find(el.first)) {
                queue.DecreaseKey(el);
            }
        }
    }
    std::cout << count;
}
