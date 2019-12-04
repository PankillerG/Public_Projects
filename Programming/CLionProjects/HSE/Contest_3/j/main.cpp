#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    unordered_map <string, long long> summ;
    unordered_map <string, long long> count;
    string name;
    long long n, mark;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> name >> mark;
        if (summ.find(name) == summ.end()) {
            summ[name] = mark;
            count[name] = 1;
        } else {
            summ[name] += mark;
            count[name] += 1;
        }
        cout << summ[name] / count[name] << "\n";
    }
    return 0;
}
