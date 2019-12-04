#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    size_t passer = 0;
    int answer = 0;
    for (uint8_t ch : str) {
        if (passer != 0) {
            answer *= 64;
            answer += static_cast<int>(ch - 128);
            if (passer == 1) {
                cout << answer << " ";
            }
            passer--;
        } else {
            if (static_cast<int>(ch >> 7) == 0) {
                cout << static_cast<int>(ch) << " ";
            } else if (static_cast<int>(ch >> 5) == 6) {
                answer = static_cast<int>(ch - 192);
                passer = 1;
            } else if (static_cast<int>(ch >> 4) == 14) {
                answer = static_cast<int>(ch - 224);
                passer = 2;
            } else if (static_cast<int>(ch >> 3) == 30) {
                answer = static_cast<int>(ch - 240);
                passer = 3;
            }
        }
    }
    return 0;
}
