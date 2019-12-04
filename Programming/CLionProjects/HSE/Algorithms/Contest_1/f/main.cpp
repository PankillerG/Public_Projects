#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int inf = 214748364;
template <typename T>
class my_heap {
 private:
    vector<int> data_graph;

 public:
    my_heap() {}
    my_heap(int number,
            int other = 0) {
        data_graph.resize(number);
        if (other != 0) {
            for (size_t i = 0;
                 i < number;
                 i++) {
                data_graph[i] = other;
            }
        }
    }
    my_heap(T begin,
            T end) {}
    my_heap(const initializer_list <int> & other) {}

        void heapify(int parent) {
        bool flag = true;
        while (flag) {
            int left;
            left = 2 * parent + 1;
            int right;
            right = 2 * parent + 2;
            int minimum;
            minimum = data_graph[parent];
            int child_minimum;
            child_minimum = left;
            int temp = data_graph.size() - 1;
            if (left <= temp &&
                minimum > data_graph[left]) {
                    minimum = data_graph[left];
                    child_minimum = left;
            }
            temp = data_graph.size() - 1;
            if (right <= temp &&
                minimum > data_graph[right]) {
                    minimum = data_graph[right];
                    child_minimum = right;
            }
            if (data_graph[parent] != minimum) {
                std::swap(data_graph[parent],
                          data_graph[child_minimum]);
                parent = child_minimum;
            } else {
                flag = false;
            }
        }
    }

    void build_heap(vector <int>& source) {
        for (int i : source) {
            data_graph.push_back(i);
        }
        int i = data_graph.size() - 1;
        while (i >= 0) {
            heapify(i);
            i--;
        }
    }

    void insert(int number) {
        data_graph.push_back(number);
        int id;
        id = data_graph.size() - 1;
        int before;
        before = (id - 1) / 2;
        while (id > 0 &&
               data_graph[id] < data_graph[number]) {
            std::swap(data_graph[id], data_graph[number]);
            id = number;
            number = (id - 1) / 2;
        }
    }

    int min_out() {
        int answer = data_graph[0];
        int temp = data_graph.size() - 1;
        data_graph[0] = data_graph[temp];
        data_graph.pop_back();
        if (data_graph.size() != 0) {
            heapify(0);
        }
        return answer;
    }

    void decrease_key(int one,
                      int two) {
        data_graph[one] = two;
        while (one >= 0 &&
               data_graph[one] < data_graph[(one - 1)/2]) {
            std::swap(data_graph[one], data_graph[(one - 1) / 2]);
            one = (one - 1) / 2;
        }
        int i = (data_graph.size() - 1) / 2;
        while (i >= 0) {
            heapify(i);
            i--;
        }
    }

    size_t size() const {
        return data_graph.size();
    }
    bool empty() const {
        if (data_graph.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    void pop() {
        int temp = data_graph.size() - 1;
        data_graph[0] = data_graph[temp];
        data_graph.pop_back();
        if (data_graph.size() != 0) {
            heapify(0);
        }
    }
    int top() const {
        return data_graph[0];
    }
};

    int funct_for_ex() {
        int n, m;
        cin >> n
            >> m;
        vector<vector<int>> w(n);
        vector<vector<int>> in_list;
        in_list.resize(n);
        vector <int> moneys;
        for (size_t i = 0;
             i < n;
             i++) {
                moneys.push_back(inf);
        }
        for (size_t i = 0;
             i < m;
             i++) {
            int p1;
            int p2;
            cin >> p1
                >> p2;
            in_list[p1 - 1].push_back(p2 - 1);
            in_list[p2 - 1].push_back(p1 - 1);
            w[p1 - 1].push_back(0);
            w[p2 - 1].push_back(0);
        }
        int local_;
        cin >> local_;
        for (size_t i = 0;
             i < local_;
             i++) {
            int p1;
            int p2;
            int moneys;
            cin >> p1
                >> p2
                >> moneys;
            in_list[p1 - 1].push_back(p2 - 1);
            in_list[p2 - 1].push_back(p1 - 1);
            w[p1 - 1].push_back(moneys);
            w[p2 - 1].push_back(moneys);
        }
        int one;
        int two;
        cin >> one
            >> two;
        moneys[one - 1] = 0;
        vector <int> queue;
        for (size_t i = 0;
             i < in_list[one-1].size();
             i++) {
            if (moneys[in_list[one-1][i]] > w[one - 1][i]) {
                moneys[in_list[one-1][i]] = w[one - 1][i];
                queue.push_back(in_list[one-1][i]);
            }
        }
        while (queue.size() != 0) {
            auto el = queue[queue.size() - 1];
            queue.pop_back();
            for (size_t i = 0;
                 i < in_list[el].size();
                 i++) {
                auto temp = w[el][i] + moneys[el];
                if (moneys[in_list[el][i]] > temp) {
                    moneys[in_list[el][i]] = temp;
                    queue.push_back(in_list[el][i]);
                }
            }
        }
        if (moneys[two - 1] == inf) {
            return -1;
        } else {
            return moneys[two - 1];
        }
    }


int main() {
    std::cout << funct_for_ex();
}
