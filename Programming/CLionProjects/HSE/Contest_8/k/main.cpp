#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    size_t passer = 0, counter = 0;
    for (uint8_t ch : str) {
        if (passer != 0) {
            passer--;
        } else {
            if (static_cast<int>(ch >> 6) <= 2) {
                counter++;
            } else if (static_cast<int>(ch >> 5) <= 6) {
                counter++;
                passer = 1;
            } else if (static_cast<int>(ch >> 4) <= 14) {
                counter++;
                passer = 2;
            } else if (static_cast<int>(ch >> 3) <= 30) {
                counter++;
                passer = 3;
            }
        }
    }
    cout << counter;
    return 0;
}

