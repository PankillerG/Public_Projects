#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    long int day;
    long int month;
    long int year;
    int long mark;
    int c;
    vector<string> preference;
};

int main() {
    map<string, long long int> universities;
    long long n;
    long long m;
    vector <Student> students;
    cin >> n;
    for (long int i = 0; i != n; i++) {
        string univercity;
        long long int quantity;
        cin >> univercity >> quantity;
        universities[univercity] = quantity;
    }
    cin >> m;
    for (long int i = 0; i != m; i++) {
        Student temp_1;
        cin >> temp_1.name;
        cin >> temp_1.surname;
        cin >> temp_1.day;
        cin >> temp_1.month;
        cin >> temp_1.year;
        cin >> temp_1.mark;
        cin >> temp_1.c;
        for (int j = 0; j != temp_1.c; j++) {
            string local;
            cin >> local;
            temp_1.preference.push_back(move(local));
        }
        students.push_back(temp_1);
    }
    sort(
        students.begin(),
        students.end(),
        [](Student st1, Student st2){
            if (st1.mark != st2.mark)
                return st1.mark > st2.mark;
            else if (st1.day != st2.day || st1.month != st2.month || st1.year != st2.year)
                return st1.day + st1.month * 30 + st1.year * 365 <
                st2.day + st2.month * 30 + st2.year * 365;
            else
                return st1.surname + st1.name < st2.surname + st2.name;
    });
    map <string, vector<Student>> ans;
    for (auto temp_1 : students) {
        int i = 0;
        while (i != temp_1.c && ans[temp_1.preference[i]].size() >=
        universities[temp_1.preference[i]]) {
            i++;
        }
        if (i < temp_1.c) {
            ans[temp_1.preference[i]].push_back(temp_1);
        }
    }
    for (auto u : ans) {
        sort(ans[u.first].begin(), ans[u.first].end(), [](Student st1, Student st2) {
            return st1.surname + st1.name < st2.surname + st2.name;
        });
    }
    for (auto temp_1 : universities) {
        cout << temp_1.first;
        for (int i = 0; i < ans[temp_1.first].size(); i++) {
            cout << "\t" <<
            ans[temp_1.first][i].name
            << " " << ans[temp_1.first][i].surname;
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

