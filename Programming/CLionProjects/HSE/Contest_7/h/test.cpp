#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
class Polynomial {
private:
    vector<T> P;
    void zero() {
        while (
            !(P.empty()) &&
            P.back() == static_cast<T>(0))
            P.pop_back();
    }

public:
    Polynomial(const vector<T>& v) {
        P = v;
        zero();
    }

    Polynomial(const T& c = T(0)) {
        vector<T> now;
        now.push_back(c);
        P = now;
        zero();
    }

    ~Polynomial() {
        P.clear();
    }

    template <typename InIter>
    Polynomial(InIter first, InIter last) {
        while (first != last) {
            P.push_back(*first);
            ++first;
        }
        zero();
    }

    const T operator[] (const size_t i) const {
        if (i >= P.size()) {
            return static_cast<T>(0);
        }
        return P[i];
    }

    Polynomial<T>& operator+= (const Polynomial& p) {
        *this = *this + p;
        zero();
        return *this;
    }

    Polynomial<T>& operator-= (const Polynomial& p) {
        *this = *this - p;
        zero();
        return *this;
    }

    Polynomial<T>& operator*= (const Polynomial& p) {
        *this = *this * p;
        zero();
        return *this;
    }

    Polynomial<T>& operator+= (const T& c) {
        Polynomial<T> p(c);
        *this = *this + p;
        zero();
        return *this;
    }

    Polynomial<T>& operator-= (const T& c) {
        Polynomial<T> p(c);
        *this = *this - p;
        zero();
        return *this;
    }

    Polynomial<T>& operator*= (const T& c) {
        Polynomial<T> p(c);
        *this = *this * p;
        zero();
        return *this;
    }

    Polynomial<T> operator+ (const Polynomial& p) const {
        int m = max(static_cast<int>(P.size()) - 1, p.Degree());
        vector<T> result;
        for (int i = 0; i < static_cast<int>(P.size()); ++i) {
            result.push_back(p[i] + P[i]);
        }
        for (int i = static_cast<int>(P.size()); i <= m; ++i) {
            result.push_back(p[i]);
        }
        return result;
    }

    Polynomial<T> operator- (const Polynomial& p) const {
        int m = max(static_cast<int>(P.size()) - 1, p.Degree());
        vector<T> result;
        for (int i = 0; i < static_cast<int>(P.size()); ++i) {
            result.push_back(P[i] - p[i]);
        }
        for (int i = static_cast<int>(P.size()); i <= m; ++i) {
            result.push_back(T(0) - p[i]);
        }
        return result;
    }

    Polynomial<T> operator* (const Polynomial& p) const {
        vector<T> result;
        result.resize(p.Degree() + static_cast<int>(P.size()) + 1);
        for (int i = 0; i < static_cast<int>(P.size()); ++i) {
            for (int j = 0; j <= p.Degree(); ++j) {
                result[i + j] += p[j] * P[i];
            }
        }
        return result;
    }

    Polynomial<T> operator+ (const T& c) const {
        Polynomial<T> C(c);
        return *this + C;
    }

    Polynomial<T> operator- (const T& c) const {
        Polynomial<T> C(c);
        return *this - C;
    }

    Polynomial<T> operator* (const T& c) const {
        Polynomial<T> C(c);
        return *this * C;
    }

    int Degree() const {
        return static_cast<int>(P.size()) - 1;
    }

    T operator() (const T& x) const {
        if (P.empty()) {
            return T(0);
        }
        T result = P[P.size() - 1];
        for (int i = static_cast<int>(P.size() - 2); i >= 0; --i) {
            result = result * x + P[i];
        }
        return result;
    }

    const auto begin() const {
        return P.begin();
    }

    const auto end() const {
        if (P.empty()) {
            return P.end();
        }
        auto find_zero = --P.end();
        while (*find_zero == static_cast<T>(0) && find_zero != P.begin()) {
            --find_zero;
        }
        return ++find_zero;
    }
};

template <typename T>
Polynomial<T> operator- (const T& c, const Polynomial<T>& p) {
    return ((p - c) * static_cast<T>(-1));
}

template <typename T>
Polynomial<T> operator+ (const T& c, const Polynomial<T>& p) {
    return (p + c);
}

template <typename T>
Polynomial<T> operator* (const T& c, const Polynomial<T>& p) {
    return (p * c);
}

template <typename T>
bool operator== (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    int m = max(p1.Degree(), p2.Degree());
    for (int i = 0; i <= m; ++i) {
        if (p1[i] != p2[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!= (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    return !(p1 == p2);
}

template <typename T>
bool operator== (const Polynomial<T>& p, const T& c) {
    Polynomial<T> C(c);
    return (p == C);
}

template <typename T>
bool operator!= (const Polynomial<T>& p, const T& c) {
    Polynomial<T> C(c);
    return (p != C);
}

template <typename T>
bool operator== (const T& c, const Polynomial<T>& p) {
    return (p == c);
}

template <typename T>
bool operator!= (const T& c, const Polynomial<T>& p) {
    return (p != c);
}

template <typename T>
ostream& operator<< (ostream& out, const Polynomial<T>& p) {
    int i = p.Degree();
    if (i == -1) {
        out << T(0);
        return out;
    }
    if (i == 0) {
        out << p[i];
    } else if (p[i] == T(1)) {
        out << "x";
        if (i > 1) {
            out << "^" << i;
        }
    } else if (p[i] == T(-1)) {
        out << "-x";
        if (i > 1) {
            out << "^" << i;
        }
    } else if (p[i] != T(0)) {
        if (i > 1) {
            out << p[i] << "*x^" << i;
        } else {
            cout << p[i] << "*x";
        }
    }
    --i;
    while (i >= 1) {
        if (p[i] != T(0)) {
            if (p[i] > T(0)) {
                out << "+";
            }
            if (p[i] == T(1)) {
                out << "x";
            } else if (p[i] == T(-1)) {
                out << "-x";
            } else {
                out << p[i] << "*x";
            }
            if (i > 1) {
                out << "^" << i;
            }
        }
        --i;
    }
    if (p[i] != T(0)) {
        if (p[i] > T(0)) {
            out << "+";
        }
        out << p[i];
    }
    return out;
}