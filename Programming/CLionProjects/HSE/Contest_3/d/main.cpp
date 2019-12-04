#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    map <char, int> chars_1;
    vector<pair<char, int>> chars_2;
    int max = 0;
    while (cin >> word) {
        for (size_t i = 0; i < word.size(); ++i) {
            ++chars_1[word[i]];
            if (chars_1[word[i]] > max) {
                max = chars_1[word[i]];
            }
        }
    }
    for (auto elem : chars_1) {
        chars_2.push_back(elem);
    }
    sort(chars_2.begin(), chars_2.end(), [](const auto& ch1, const auto& ch2) {
            return ch1.first < ch2.first;
        });
    for (size_t i = 0; i < max; i++) {
        for (size_t j = 0; j < chars_2.size(); j++) {
            if (chars_2[j].second < max - i) {
                if (j == chars_2.size() - 1) {
                    if (i == max - 1) {
                        cout << " ";
                    } else {
                        cout << "\n";
                    }
                } else {
                    cout << " ";
                }
            } else {
                if (j == chars_2.size() - 1) {
                    if (i == max - 1) {
                        cout << "#";
                    } else {
                        cout << "#" << "\n";
                    }
                } else {
                    cout << "#";
                }
            }
        }
    }
    cout << "\n";
    for (size_t i = 0; i < chars_2.size(); i++) {
        cout << chars_2[i].first;
    }
    return 0;
}
