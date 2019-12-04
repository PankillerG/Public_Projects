#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    string first_w;
    vector <string> words;
    int maximum = 0, local, sk;
    vector <int> first_vect;
    cin >> first_w;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        first_vect.push_back(local);
    }
    string local_str;
    bool flag = true;
    for (size_t i = 1; i < m; i++) {
        cin >> local_str;
        sk = 0;
        for (size_t j = 0; j < n; j++) {
            cin >> local;
            sk += (first_vect[j] * local);
        }
        if (flag) {
            maximum = sk;
            flag = false;
        }
        if (sk > maximum) {
            maximum = sk;
            words.clear();
            words.push_back(local_str);
        } else if (sk == maximum) {
            words.push_back(local_str);
        }
    }
    for (auto w : words) {
        cout << w << "\n";
    }
    return 0;
}
