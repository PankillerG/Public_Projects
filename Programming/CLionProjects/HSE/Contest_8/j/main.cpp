#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string s;
    getline(std::cin, s);
    long long power = 1;
    uint64_t answer;
    for (uint8_t byte : s) {
        answer += (byte % 128) * power;
        power *= 128;
    }
    cout << answer;
    return 0;
}
