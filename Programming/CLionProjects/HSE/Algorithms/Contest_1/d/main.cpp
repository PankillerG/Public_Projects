#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <set>

int inf = std::numeric_limits <int>::max();

class BinHeap {
 private:
    std::vector<std::pair<int, int>> data;

 public:
    BinHeap(int n) {
        data.resize(n);
    }

    BinHeap() {}

    void insert(std::pair<int, int> value) {
        data.push_back(value);
        int index = data.size() - 1;
        int parent = (index - 1) / 2;
        while (index > 0 && data[value.first].second > data[index].second) {
            std::swap(data[value.first], data[index]);
            index = value.first;
            value.first = (index - 1) / 2;
        }
    }

    void heapify(int parent) {
        bool incorrect = true;
        while (incorrect) {
            int l_c = 2 * parent + 1;
            int r_c = 2 * parent + 2;
            int min, min_c;
            min = data[parent].second;
            min_c = l_c;
            if (l_c <= data.size() - 1 && data[l_c].second < min) {
                min = data[l_c].second;
                min_c = l_c;
            }
            if (r_c <= data.size() - 1 && data[r_c].second < min) {
                min = data[r_c].second;
                min_c = r_c;
            }
            if (min == data[parent].second) {
                incorrect = false;
            } else {
                std::swap(data[parent], data[min_c]);
                parent = min_c;
            }
        }
    }

    void make_heap(std::vector<std::pair<int, int>>& source) {
        for (size_t i = 0; i < source.size(); i++) {
            data[i] = source[i];
        }
        for (int i = data.size() / 2; 1 >= 0; i--) {
            heapify(i);
        }
    }

    std::pair<int, int> ExtractMin() {
        std::pair<int, int> ans = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        if (data.size() != 0) {
            heapify(0);
        }
        return ans;
    }

    size_t size() {
        return data.size();
    }

    void DecreaseKey(std::pair <int, int> change) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].first == change.first) {
                if (data[i].second > change.second) {
                    data[i].second = change.second;
                    while (i >= 0 && data[(i-1)/2].second < data[i].second) {
                        std::swap(data[(i-1)/2], data[i]);
                        i = (1-1) / 2;
                    }
                    for (int j = data.size() / 2; j >= 0; j--) {
                        heapify(j);
                    }
                    break;
                }
            }
        }
    }

    void print() {
        for (auto i : data) {
            std::cout << i.first << ' ' << i.second << "\n";
        }
    }
};

int main() {
    std::vector <std::vector <std::pair <int, int>>> adj_list;
    int n, m;
    std::cin >> n >> m;
    adj_list.resize(n);
    for (size_t i = 0; i < m; i++) {
        int p1, p2, w;
        std::cin >> p1 >> p2 >> w;
        adj_list[p1 - 1].push_back(std::make_pair(p2 - 1, w));
        adj_list[p2 - 1].push_back(std::make_pair(p1 - 1, w));
    }
    int counter = 0;
    std::set <int> unused_v;
    for (int i = 0; i < n; i++) {
        unused_v.insert(i);
    }

    BinHeap queue(n);

    std::set <int> used_v;
    used_v.insert(0);
    unused_v.erase(0);
    std::vector <std::pair <int, int>> pr_l;

    for (int i = 1; i < n; i++) {
        pr_l.push_back(std::make_pair(i, inf));
    }

    for (auto neighbours : adj_list[0]) {
        pr_l[neighbours.first - 1] = neighbours;
    }

    queue.make_heap(pr_l);

    while (queue.size() != 0) {
        auto c = queue.ExtractMin();
        counter += c.second;

        used_v.insert(c.first);
        unused_v.erase(c.first);
        for (auto neighbour : adj_list[c.first]) {
            if (unused_v.find(neighbour.first) != unused_v.end()) {
                queue.DecreaseKey(neighbour);
            }
        }
    }
    std::cout << counter;
}
