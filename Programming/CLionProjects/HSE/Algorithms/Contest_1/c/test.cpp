#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

long dj(long first,
        long last,
        const std::vector <std::vector <std::tuple <long, long, long>>>& graph,
        long weight) {
    long n = graph.size();
    long max_dist = 3000000;

    std::priority_queue <std::tuple <long, long>,
                    std::vector <std::tuple <long, long>>,
                    std::greater <std::tuple <long, long>>> my_queue;
    std::vector <long> distation(n,
                                 max_dist);
    distation[first] = 0;
    my_queue.push(std::make_tuple(0,
                                  first));

    while (my_queue.size() != 0) {
        long distation_now;
        long now;
        std::tie(distation_now, now) = my_queue.top();
        my_queue.pop();
        if (distation[now] < distation_now) {
            continue;
        }

        for (auto& ell : graph[now]) {
            long max_weight;
            long adj_distance;
            long adj;
            long size_;

            std::tie(adj, size_, max_weight) = ell;
            adj_distance = distation_now + size_;
            if (adj_distance < distation[adj]
                && weight <= max_weight) {
                    my_queue.push(std::make_tuple(adj_distance, adj));
                    distation[adj] = adj_distance;
            }
        }
    }

    if (distation[last] == max_dist) {
        return -1;
    } else {
        return distation[last];
    }
}


int main() {
    long n, m;
    std::cin >> n >> m;
    std::vector <std::vector <std::tuple<long, long, long>>> graph(n);
    for (long i = 0;
         i < m;
         i++) {
            long temp_2;
            long temp_1;
            long left;
            long w;
        std::cin >> temp_2
                 >> temp_1
                 >> left
                 >> w;

        temp_1 -= 1;
        temp_2 -= 1;

        graph[temp_2].push_back(std::make_tuple(temp_1, left, w));
        graph[temp_1].push_back(std::make_tuple(temp_2, left, w));
    }

    long left = 0;
    long right = 10000100;
    long middle, val_mid;

    while (right - left > 1) {
        middle = left + right;
        middle /= 2;
        val_mid = dj(0, n - 1, graph, 100 * middle + 3000000);
        if (val_mid <= 1440 &&
            val_mid >= 0) {
                left = middle;
        } else {
            right = middle;
        }
    }

    std::cout << std::min(long(left), long(10000000));

    return 0;
}
