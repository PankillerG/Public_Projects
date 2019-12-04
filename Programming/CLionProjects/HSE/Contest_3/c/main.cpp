#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Student {
        string name;
        string surname;
        int day;
        int month;
        int year;
};

int main() {
    size_t n;
    cin >> n;
    vector <Student> students;
    students.resize(n);
    string name, surname;
    int day, month, year;
    for (size_t i = 0; i < n; i++) {
        cin >> name >> surname >> day >> month >> year;
        students[i].name = name;
        students[i].surname = surname;
        students[i].day = day;
        students[i].month = month;
        students[i].year = year;
    }
    size_t k;
    cin >> k;
    string local_1;
    int local_2;
    for (size_t i = 0; i < k; i++) {
        cin >> local_1 >> local_2;
        local_2--;
        if (local_1 == "name" && local_2 >= 0 && local_2 < n) {
            cout << students[local_2].name << " " << students[local_2].surname << "\n";
        } else if (local_1 == "date" && local_2 >= 0 && local_2 < n) {
            cout << students[local_2].day << "." << students[local_2].month << "."
                << students[local_2].year << "\n";
        } else {
            cout << "bad request" << "\n";
        }
    }
    return 0;
}
