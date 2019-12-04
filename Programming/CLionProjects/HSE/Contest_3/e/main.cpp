#include <iostream>
#include <map>

using namespace std;

int main() {
    map <int, int> numbers;
    int n;
    while (cin >> n) {
        ++numbers[n];
        if (numbers[n] > 1) {
        cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}