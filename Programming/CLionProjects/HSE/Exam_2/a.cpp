#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector <string> all;
    string func;
    getline(cin, func);
    string local;
    while (getline(cin, local)) {
        all.push_back(local);
    }
    if (func == "ASCENDING") {
        sort(
            all.begin(),
            all.end(),
            [](const auto& s1, const auto& s2) {
                return s1 < s2;
            });
    } else {
        sort(
            all.begin(),
            all.end(),
            [](const auto& s1, const auto& s2) {
                return s1 > s2;
            });
    }
    for (size_t i = 0; i < all.size(); i++) {
        cout << all[i] << "\n";
    }
    return 0;
}
