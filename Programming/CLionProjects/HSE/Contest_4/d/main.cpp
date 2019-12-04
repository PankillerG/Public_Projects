#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque <string> students;
    string name, place;
    for (size_t i = 0; i < n; i++) {
        cin >> name >> place;
        if (place == "top") {
            students.push_front(name);
        } else {
            students.push_back(name);
        }
    }
    cin >> n;
    int num;
    for (size_t i = 0; i < n; i++) {
        cin >> num;
        cout << students[num - 1] << "\n";
    }
    return 0;
}
