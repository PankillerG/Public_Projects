#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string local;
    priority_queue <int> numbers;
    while (cin >> local) {
        if (local == "CLEAR") {
            while (numbers.size() != 0) {
                numbers.pop();
            }
        }
        if (local == "ADD") {
            int n;
            cin >> n;
            numbers.push(n);
        }
        if (local == "EXTRACT") {
            if (numbers.size() != 0) {
                cout << numbers.top() << "\n";
                numbers.pop();
            } else {
                cout << "CANNOT" << "\n";
            }
        }
    }
    return 0;
}
