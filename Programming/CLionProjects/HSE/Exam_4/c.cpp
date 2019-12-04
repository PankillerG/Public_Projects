#include <iostream>
#include <ios>

using namespace std;

int main() {
    int val;
    while (std::cin >> std::hex >> val) {
        cout << char(val);
    }
    return 0;
}
