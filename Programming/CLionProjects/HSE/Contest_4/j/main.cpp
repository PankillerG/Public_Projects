#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue <int> first;
    queue <int> second;
    int local;
    for (size_t i = 0; i < 5; i++) {
        cin >> local;
        first.push(local);
    }
    for (size_t i = 0; i < 5; i++) {
        cin >> local;
        second.push(local);
    }
    int local_first, local_second, count = 0;
    while (first.size() != 0 &&
    second.size() != 0 &&
    count <= 1000000) {
        local_first = first.front();
        first.pop();
        local_second = second.front();
        second.pop();
        if (local_first == 0 && local_second == 9) {
            first.push(local_first);
            first.push(local_second);
        } else if (local_second == 0 && local_first == 9) {
            second.push(local_first);
            second.push(local_second);
        } else if (local_first > local_second) {
            first.push(local_first);
            first.push(local_second);
        } else if (local_second > local_first) {
            second.push(local_first);
            second.push(local_second);
        }
        count += 1;
    }
    if (first.size() != 0 && count <= 1000000) {
        cout << "first" << " " << count;
    } else if (second.size() != 0 && count <= 1000000) {
        cout << "second" << " " << count;
    } else {
        cout << "botva";
    }
    return 0;
}
