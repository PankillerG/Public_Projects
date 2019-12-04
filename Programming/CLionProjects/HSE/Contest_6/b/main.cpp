#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;

class Rational {
 private:
    int num = 0;
    int den = 1;

 public:
    Rational(const int up, const int down) {
        num = up;
        den = down;
        good_d();
    }
    Rational(const int up) {
        num = up;
        good_d();
    }
    Rational() {}

    Rational& good_d() {
        if (den < 0) {
            den = -den;
            num = -num;
        }
        int local;
        local = gcd(abs(num), abs(den));
        num /= local;
        den /= local;
        return *this;
    }

    int numerator() const {
        return num;
    }
    int denominator() const {
        return den;
    }

    Rational operator +(const Rational& other) const {
        return Rational(num * other.den + other.num * den,
        den * other.den);
    }
    Rational operator +(const int& other) const {
        return Rational(num + other * den, den);
    }

    Rational operator -(const Rational& other) const {
        return Rational(num * other.den - other.num * den,
        den * other.den);
    }
    Rational operator -(const int& other) const {
        return Rational(num - other * den, den);
    }

    Rational operator *(const Rational& other) const {
        return Rational(num * other.num, den * other.den);
    }
    Rational operator *(const int& other) const {
        return Rational(num * other, den);
    }

    Rational operator /(const Rational& other) const {
        return Rational(num * other.den, den * other.num);
    }
    Rational operator /(const int& other) const {
        return Rational(num, den * other);
    }

    Rational operator +() const {
        return *this;
    }

    Rational operator -() const {
        return Rational(-num, den);
    }

    Rational operator +=(const Rational& other) {
        *this = *this + other;
        return *this;
    }
    Rational operator +=(const int& other) {
        *this = *this + other;
        return *this;
    }

    Rational operator -=(const Rational& other) {
        *this = *this - other;
        return *this;
    }
    Rational operator -=(const int& other) {
        *this = *this - other;
        return *this;
    }

    Rational operator *=(const Rational& other) {
        *this = *this * other;
        return *this;
    }
    Rational operator *=(const int& other) {
        *this = *this * other;
        return *this;
    }

    Rational operator /=(const Rational& other) {
        *this = *this / other;
        return *this;
    }
    Rational operator /=(const int& other) {
        *this = *this / other;
        return *this;
    }

    bool operator ==(const Rational& other) const {
        return num == other.num && den == other.den;
    }

    bool operator !=(const Rational& other) const {
        return !(*this == other);
    }

    Rational& operator ++() {
        *this = *this + 1;
        return *this;
    }

    Rational operator ++(int) {
        Rational temp = *this;
        *this = *this + 1;
        return temp;
    }

    Rational& operator --() {
        *this = *this - 1;
        return *this;
    }

    Rational operator --(int) {
        Rational temp = *this;
        *this = *this - 1;
        return temp;
    }
};

Rational operator +(const int first, const Rational& second) {
    return Rational(first) + second;
}

Rational operator -(const int first, const Rational& second) {
    return Rational(first) - second;
}

Rational operator *(const int first, const Rational& second) {
    return Rational(first) * second;
}

Rational operator /(const int first, const Rational& second) {
    return Rational(first) / second;
}

ostream& operator<<(ostream& os, const Rational& a) {
    os << a.numerator();
    if (a.denominator() != 1) {
        os << "/" << a.denominator();
    }
    return os;
}

int main() {
    Rational a{1, 1};
    cout << a;
    return 0;
}