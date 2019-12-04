#include <iostream>
#include <map>
#include <set>


using namespace std;

int main() {
    int m;
    cin >> m;
    string local;
    set <string> view;
    for (size_t i = 0; i < m; i++) {
        cin >> local;
        view.insert(local);
    }
    int n;
    cin >> n;
    map <string, int> ans;
    for (size_t i = 0; i < n; i++) {
        cin >> local;
        for (auto v : view) {
            int count = 0;
            for (auto ch : local) {
                if (v.find(ch) != v.end()) {
                    count += 1;
                }
            }
            if (local.size() == count) {
                ans[local]++;
            }
        }
    }
    cout << ans.size();
    for (auto c : ans) {
        cout << c.first << " " << c.second << "\n";
    }
    return 0;
}
