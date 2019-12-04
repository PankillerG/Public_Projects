#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

map<string, int> final_standings(const vector<map<string, int> >& vect) {
    int local = vect.size();
    map<string, int> all;
    for (size_t i = 0; i < local; i++) {
        for (auto c : vect[i]) {
            if (all.find(c.first) != all.end()) {
                all[c.first] = max(all[c.first], c.second);
            } else {
                all[c.first] = c.second;
            }
        }
    }
    return all;
}
