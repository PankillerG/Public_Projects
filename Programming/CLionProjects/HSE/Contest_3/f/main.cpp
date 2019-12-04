#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set <string> strings;
    string operation, word;
    cin >> operation;
    while (operation != "#") {
        cin >> word;
        if (operation == "+") {
            if (strings.find(word) == strings.end()) {
                strings.insert(word);
            }
        }
        if (operation == "-") {
            if (strings.find(word) != strings.end()) {
                strings.erase(word);
            }
        }
        if (operation == "?") {
            if (strings.find(word) != strings.end()) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
        cin >> operation;
    }
    return 0;
}
