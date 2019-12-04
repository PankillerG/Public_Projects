#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<char> chars;
    bool flag = false;
    string word;
    while (cin >> word) {
        if (flag) {
            for (auto ch : chars) {
                if (word.find(ch) == -1) {
                    chars.erase(ch);
                }
            }
        } else {
            for (size_t i = 0; i < word.size(); i++) {
                chars.insert(word[i]);
            }
            flag = true;
        }
    }
    for (auto ch : chars) {
        cout << ch;
    }
    return 0;
}
