#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map <string, vector<string>> all;
    string line, local_1, local_2, local_3;
    map <string, int> count;
    while (getline(cin, line)) {
        bool flag_1 = true;
        bool flag_2 = false;
        local_1 = "";
        local_2 = "";
        vector <string> loc_vect;
        for (auto ch : line) {
            if (ch != ' ' && ch != '\n' && flag_1) {
                local_1 += ch;
            } else if (flag_1) {
                flag_1 = false;
                flag_2 = true;
            } else {
                if (ch != ' ' && ch != '\n' && flag_2) {
                    local_3+= ch;
                } else if (flag_2) {
                    flag_2 = false;
                } else {
                    if (!flag_1 && ch != ' ' && ch != '\n') {
                        local_2 += ch;
                    } else if (!flag_1) {
                        if (local_2 != "") {
                            loc_vect.push_back(local_2);
                        }
                        local_2 = "";
                    }
                }
            }
        }
        if (local_2 != "") {
            loc_vect.push_back(local_2);
        }
        all[local_1] = loc_vect;
        count[local_1] = stoi(local_3);
        local_3 = "";
    }
    for (auto a : all) {
        cout << a.first << " ";
        for (auto v : a.second) {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (auto c : count) {
        cout << c.first << " " << c.second << "\n";
    }

    for (auto a : all) {
        if (a.second.size() == 0) {
            cout << a.first << " ";
            for (size_t i = 1; i <= count[a.first]; i++) {
                if (i == count[a.first]) {
                    cout << i << "\n";
                    break;
                }
                cout << i << " ";
            }
        } else {
            string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            if (str.find(a.second[0]) != -1) {
                vector <char> alf;
                for (size_t i = 0; i < count[a.first]; i++) {
                    alf.push_back(str[i]);
                }
                vector <string> local;
                local.resize(alf.size() - a.second.size());
                cout << local.size();
                //set_difference(alf.begin(), alf.end(), a.second.begin(), a.second.end(), local.begin());
                for (size_t i = 0; i < local.size(); i++) {
                    if (i + 1 == local.size()) {
                        cout << local[i] << "\n";
                    } else {
                        cout << local[i] << " ";
                    }
                }
            }

        }
    }
    return 0;
}

