#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
    string str;
    vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F',
                          'G', 'H', 'I', 'J', 'K', 'L',
                          'M', 'N', 'O', 'P', 'Q', 'R',
                          'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> numbers = {1, 2, 3, 4, 5,
                           6, 7, 8, 9, 10,
                           11, 12, 13, 14, 15,
                           16, 17, 18, 19, 20};
    while (getline(cin, str)) {
        string number_cont, many;
        int i = 0;
        int j;
        while (str[i] != ' ') {
            number_cont.push_back(str[i]);
            i++;
        }
        j = i + 1;
        while (j != str.size() && str[j] != ' ') {
            many.push_back(str[j]);
            j++;
        }
        cout << number_cont << ' ';
        int counter = stoi(many);
        if (j == str.size()) {
            vector<int> all(counter);
            for (size_t i = 0; i != counter; i++) {
                all[i] = numbers[i];
            }
            for (auto a : all) {
                cout << a << ' ';
            }
            cout << '\n';
        } else if (isdigit(str[j + 1])) {
            int k = j + 1;
            vector<int> all;
            string num;
            vector<int> local;
            while (k != str.size()) {
                if (str[k] == ' ') {
                    int temp = stoi(num);
                    local.push_back(temp);
                    num = "";
                } else {
                    num.push_back(str[k]);
                }
                k++;
            }
            int temp = stoi(num);
            local.push_back(temp);
            vector<int>::iterator local_2;
            local_2 = numbers.begin();
            local_2 += counter;
            set_difference(
                numbers.begin(),
                local_2,
                local.begin(),
                local.end(),
                inserter(all, all.begin()));
            for (auto a : all) {
                cout << a << ' ';
            }
            cout << '\n';
        } else if (!isdigit(str[j + 1])) {
            vector<char> local;
            int k = j + 1;
            vector<char> all;
            while (k != str.size()) {
                if (str[k] != ' ') {
                    local.push_back(str[k]);
                }
                k++;
            }
            vector<char>::iterator local_2;
            local_2 = chars.begin();
            local_2 = local_2 + counter;
            set_difference(
                chars.begin(),
                local_2,
                local.begin(),
                local.end(),
                inserter(all, all.begin()));
            for (auto a : all) {
                cout << a << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
