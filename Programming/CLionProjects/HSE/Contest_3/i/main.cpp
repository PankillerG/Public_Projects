#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    string direct;
    vector <string> all;
    set <string> once;
    while (getline(cin, line)) {
        direct = "";
        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] == '/') {
                direct += "/";
                if (once.find(direct) == once.end()) {
                    once.insert(direct);
                    if (direct != "/") {
                        all.push_back(direct);
                    } else {
                        all.push_back(direct);
                    }
                }
            } else {
                direct += line[i];
            }
        }
    }
    sort(
        all.begin(),
        all.end());
    for (size_t i = 0; i < all.size(); i++) {
        cout << all[i] << "\n";
    }
    return 0;
}
