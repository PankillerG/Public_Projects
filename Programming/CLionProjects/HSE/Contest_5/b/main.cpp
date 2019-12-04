#include <iostream>
#include <algorithm>
#include <vector>

void delete_zeroes(std::vector<int>& numbers) {
    numbers.erase(std::remove(numbers.begin(),
    numbers.end(), 0), numbers.end());
}

using namespace std;

int main() {
    vector <int> all;
    int n;
    while (cin >> n) {
        all.push_back(n);
    }
    delete_zeroes(all);
    for (auto c : all) {
        cout << c << " ";
    }
    return 0;
}
