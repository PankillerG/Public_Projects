#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    string local;
    set <string> words;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        words.insert(local);
    }
    vector <string> req;
    while (cin >> local) {
        req.push_back(local);
    }
    sort(req.begin(), req.end());
    set <string> check;
    for (auto s : req) {
        if (words.find(s) == words.end() &&
        check.find(s) == check.end()) {
            cout << s << "\n";
            check.insert(s);
        }
    }
    return 0;
}
