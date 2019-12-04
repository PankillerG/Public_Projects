#include <iostream>

using namespace std;

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    int day_ans, month_ans, year_ans;
    if (month == 1 || month == 3 || month == 5 || month == 7
    || month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 29) {
            day_ans = day + 2;
            month_ans = month;
            year_ans = year;
        } else if (day == 30) {
            day_ans = 1;
            if (month == 12) {
                month_ans = 1;
                year_ans = year + 1;
            } else {
                month_ans = month + 1;
                year_ans = year;
            }
        } else if (day == 31) {
            day_ans = 2;
            if (month == 12) {
                month_ans = 1;
                year_ans = year + 1;
            } else {
                month_ans = month + 1;
                year_ans = year;
            }
        }
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day >= 1 && day <= 27) {
                day_ans = day + 2;
                month_ans = month;
                year_ans = year;
            } else if (day == 28) {
                day_ans = 1;
                month_ans = month + 1;
                year_ans = year;
            } else if (day == 29) {
                day_ans = 2;
                month_ans = month + 1;
                year_ans = year;
            }
        } else {
            if (day >= 1 && day <= 26) {
                day_ans = day + 2;
                month_ans = month;
                year_ans = year;
            } else if (day == 27) {
                day_ans = 1;
                month_ans = month + 1;
                year_ans = year;
            } else if (day == 28) {
                day_ans = 2;
                month_ans = month + 1;
                year_ans = year;
            }
        }
    } else {
        if (day >= 1 && day <= 28) {
            day_ans = day + 2;
            month_ans = month;
            year_ans = year;
        } else if (day == 29) {
            day_ans = 1;
            month_ans = month + 1;
            year_ans = year;
        } else if (day == 30) {
            day_ans = 2;
            month_ans = month + 1;
            year_ans = year;
        }
    }
    cout << day_ans<< " " << month_ans << " " << year_ans;
    return 0;
}