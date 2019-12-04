#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Date {
 private:
    int days;

 public:
    Date(int day, int month, int year) {
        days = 0;
        for (size_t i = 1970; i <= year - 1; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for (size_t i = 1; i <= month - 1; i++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                days += 31;
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                days += 30;
            } else {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    days += 29;
                } else {
                    days += 28;
                }
            }
        }
        days += day;
    }

    int GetDay() const {
        int d = days;
        int m, y, ye;
        vector <int> mon_dates = {31, 28, 31, 30,
                                 31, 30, 31, 31,
                                 30, 31, 30, 31};
        for (size_t i = 1970; i <= 2099; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                ye = 366;
            } else {
                ye = 365;
            }
            if (d - ye > 0) {
                d -= ye;
            } else {
                y = i;
                break;
            }
        }
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            mon_dates[1] = 29;
        }
        for (size_t i = 0; i < 12; i++) {
            if (d - mon_dates[i] > 0) {
                d -= mon_dates[i];
            } else {
                m = i + 1;
                break;
            }
        }
        return d;
    }

    int GetMonth() const {
        int d = days;
        int m, y, ye;
        vector <int> mon_dates = {31, 28, 31, 30,
                                 31, 30, 31, 31,
                                 30, 31, 30, 31};
        for (size_t i = 1970; i <= 2099; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                ye = 366;
            } else {
                ye = 365;
            }
            if (d - ye > 0) {
                d -= ye;
            } else {
                y = i;
                break;
            }
        }
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            mon_dates[1] = 29;
        }
        for (size_t i = 0; i < 12; i++) {
            if (d - mon_dates[i] > 0) {
                d -= mon_dates[i];
            } else {
                m = i + 1;
                break;
            }
        }
        return m;
    }

    int GetYear() const {
        int d = days;
        int m, y, ye;
        vector <int> mon_dates = {31, 28, 31, 30,
                                 31, 30, 31, 31,
                                 30, 31, 30, 31};
        for (size_t i = 1970; i <= 2099; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                ye = 366;
            } else {
                ye = 365;
            }
            if (d - ye > 0) {
                d -= ye;
            } else {
                y = i;
                break;
            }
        }
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            mon_dates[1] = 29;
        }
        for (size_t i = 0; i < 12; i++) {
            if (d - mon_dates[i] > 0) {
                d -= mon_dates[i];
            } else {
                m = i + 1;
                break;
            }
        }
        return y;
    }

    Date operator ++() {
        days++;
        return *this;
    }

    Date operator --() {
        days--;
        return *this;
    }

    Date operator +(const int& other) {
        for (size_t i = 0; i < other; i++) {
            ++(*this);
        }
        return *this;
    }

    Date operator -(const int& other) {
        for (size_t i = 0; i < other; i++) {
            --(*this);
        }
        return *this;
    }

    int operator -(const Date& other) {
        return days - other.days;
    }
};

int main() {
    Date first(18, 4, 2000);
    cout << first.GetDay() << " " << first.GetMonth() << " " << first.GetYear() << "\n";
    first = first + 365;
    first = first + 365;
    cout << first.GetDay() << " " << first.GetMonth() << " " << first.GetYear() << "\n";
    first = first - 365;
    cout << first.GetDay() << " " << first.GetMonth() << " " << first.GetYear() << "\n";
    ++first;
    cout << first.GetDay() << " " << first.GetMonth() << " " << first.GetYear() << "\n";
    return 0;
}
