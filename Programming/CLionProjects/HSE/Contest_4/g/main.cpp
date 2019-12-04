#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack <int> numbers;
    string local;
    while (local != "exit" && cin >> local) {
        if (local == "push") {
            int n;
            cin >> n;
            numbers.push(n);
            cout << "ok" << "\n";
        }
        if (local == "pop") {
            cout << numbers.top() << "\n";
            numbers.pop();
        }
        if (local == "back") {
            cout << numbers.top() << "\n";
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
