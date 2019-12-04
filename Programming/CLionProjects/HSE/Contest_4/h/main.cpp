#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string local;
    queue <int> numbers;
    while (local != "exit" && cin >> local) {
        if (local == "push") {
            int n;
            cin >> n;
            numbers.push(n);
            cout << "ok" << "\n";
        }
        if (local == "pop") {
            if (numbers.size() != 0) {
                cout << numbers.front() << "\n";
                numbers.pop();
            } else {
                cout << "error" << "\n";
            }
        }
        if (local == "front") {
            if (numbers.size() != 0) {
                cout << numbers.front() << "\n";
            } else {
                cout << "error" << "\n";
            }
        }
        if (local == "size") {
            cout << numbers.size() << "\n";
        }
        if (local == "clear") {
            while (numbers.size() != 0) {
                numbers.pop();
            }
            cout << "ok" << "\n";
        }
        if (local == "exit") {
            cout << "bye";
        }
    }

    return 0;
}
