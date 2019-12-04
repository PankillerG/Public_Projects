#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    long long day;
    long long month;
    long long year;
    long long mark;
    vector <string> preference;
};

int main() {
    int n;
    cin >> n;
    string name_un;
    long long quantity;
    map <string, long long> universities;
    map <string, string> universities_students;
    for (size_t i = 0; i < n; i++) {
        cin >> name_un >> quantity;
        universities[name_un] = quantity;
        universities_students[name_un] = "";
    }
    int m;
    cin >> m;
    int local_1;
    string local_2;
    vector <Student> students(m);
    long long day, month, year;
    for (size_t i = 0; i < m; i++) {
        cin >> students[i].name;
        cin >> students[i].surname;
        cin >> day;
        students[i].day = -day;
        cin >> month;
        students[i].month = -month;
        cin >> year;
        students[i].year = -year;
        cin >> students[i].mark;
        cin >> local_1;
        for (size_t j = 0; j < local_1; j++) {
            cin >> local_2;
            students[i].preference.push_back(local_2);
        }
    }

    sort(
        students.begin(),
        students.end(),
        [](const Student& st1, const Student& st2) {
            return tie(st1.mark, st1.year, st1.month, st1.day, st1.surname, st1.name) >
            tie(st2.mark, st2.year, st2.month, st2.day, st2.surname, st2.name);
        });

    map <string, vector<Student>> ans;
    for (auto st : students) {
        int i;
        while (i != st.preference.size() && ans[st.preference[i]].size() >= universities[st.preference[i]]) {
            ++i;
        }
        if (i < st.preference.size()) {
            ans[st.preference[i]].push_back(st);
        }
    }

    for (auto u : ans) {
        sort(ans[u.first].begin(), ans[u.first].end(), [](Student a, Student b) {
            return a.surname + a.name < b.surname + b.name;
        });
    }

    cout << "\n \n \n";

    for (auto e : universities) {
        cout << e.first;
        for (int i = 0; i < ans[e.first].size(); ++i) {
            cout << "\t" << ans[e.first][i].name << " " << ans[e.first][i].surname;
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
