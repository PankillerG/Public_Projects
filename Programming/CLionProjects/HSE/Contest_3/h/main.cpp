#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<char> letters;
    string local;
    cin >> local;
    for (auto let : local) {
        letters.insert(let);
    }
    int n;
    cin >> n;
    bool flag;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        flag = true;
        for (auto let : local) {
            if (letters.find(let) == letters.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << local << "\n";
        }
    }
    return 0;
}
