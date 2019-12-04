Polynomial<T>& operator-= (const Polynomial<T>& other) {
        if (values.size() <= other.values.size()) values.resize(other.values.size() + 1);
        for (size_t i = 0; i < other.values.size(); ++i) {
            values[i] -= other.values[i];
        }
        return *this;
    }

    Polynomial<T> operator+ (const Polynomial<T>& other) const {
        Polynomial<T> result = *this;
        result += other;
        return result;
    }

    Polynomial<T> operator- (const Polynomial<T>& other) const {
        Polynomial<T> result = *this;
        result -= other;
        return result;
    }

    // Предусмотрите методы begin() и end() для доступа к константным итераторам,
    // позволяющим перебрать коэффициенты многочлена (это могут быть просто итераторы вектора).
    // При этом ведущие нули коэффициентами не считаются.
    // Итерация должна происходить от младших коэффициентов к старшим.

    using PolynomialIterator = typename vector<T>::const_iterator;

    PolynomialIterator begin() const {
        return values.begin();
    }

    PolynomialIterator end() const {
        PolynomialIterator result = values.end();
        while (*prev(result) == T(0)) --result;
        return result;
    }

    Polynomial<T> operator* (const Polynomial<T>& other) const {
        Polynomial<T> result = T(0);
        result.values.resize(Degree() + other.Degree() + 1);
        for (int i = 0; i <= Degree(); ++i) {
            for (int j = 0; j <= other.Degree(); ++j) {
                result.values[i+j] += values[i] * other.values[j];
            }
        }
        return result;
    }

    Polynomial<T>& operator*= (const Polynomial<T>& other) {
        *this = *this * other;
        return *this;
    }

    Polynomial<T>& operator*= (const T& other) {
        *this = *this * Polynomial<T>(other);
        return *this;
    }

    T operator() (const T& value) const {
        T result = T(0);
        vector<T> cache;
        for (size_t i = 0; i < values.size(); ++i) {
            if (values[i] != T(0))
                result += values[i] * fast_pow(value, i, cache);
        }
        return result;
    }

    Polynomial<T> operator& (const Polynomial<T>& other) const {
        Polynomial<T> result = T(0);
        vector<Polynomial<T>> cache;
        for (size_t i = 0; i < values.size(); ++i) {
            if (values[i] != T(0))
                result += values[i] * fast_pow_poly(other, i, cache);
        }
        return result;
    }

    Polynomial<T> operator/ (const Polynomial<T>& other) const {
        Polynomial<T> a = *this;
        Polynomial<T> result = T(0);
        while (a.Degree() >= other.Degree()) {
            Polynomial<T> d = T(0);
            d.values.resize(a.Degree()+1);
            d.values[a.Degree() - other.Degree()] = T(1);
            d *= a[a.Degree()] / other[other.Degree()];
            result += d;
            a -= other * d;
        }
        return result;
    }

    Polynomial<T> operator% (const Polynomial<T>& other) const {
        Polynomial<T> a = *this;
        Polynomial<T> result = T(0);
        while (a.Degree() >= other.Degree()) {
            Polynomial<T> d = T(0);
            d.values.resize(a.Degree()+1);
            d.values[a.Degree() - other.Degree()] = T(1);
            d *= a[a.Degree()] / other[other.Degree()];
            result += d;
            a -= other * d;
        }
        return a;
    }

    Polynomial<T>& operator/= (const Polynomial<T>& other) {
        *this = *this / other;
        return *this;
    }

    Polynomial<T>& operator%= (const Polynomial<T>& other) {
        *this = *this % other;
        return *this;
    }

    Polynomial<T>& normalize() {
        Polynomial<T> other((*this)[Degree()]);
        return *this /= other;
    }

    Polynomial<T> operator, (const Polynomial<T>& other) const {
        Polynomial<T> a = *this;
        Polynomial<T> b = other;
        Polynomial<T> temp;
        while (b.Degree() != -1) {
            a %= b;
            temp = a;
            a = b;
            b = temp;
        }
        if (a.Degree() != -1) {

    a.normalize();
        }
        return a;
    }
};

// Перегрузите операторы == и !=. Ваш код должен быть очень простым.
// Операторы должны работать и в том случае,
// когда один из аргументов является скаляром.
template<typename T>
bool operator== (const Polynomial<T>& a, const T& b) {
    return Polynomial<T>(b) == a;
}

template<typename T>
bool operator!= (const Polynomial<T>& a, const T& b) {
    return !(a == b);
}

template<typename T>
bool operator== (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) == b;
}

template<typename T>
bool operator!= (const T& a, const Polynomial<T>& b) {
    return !(a == b);
}

template<typename T>
Polynomial<T> operator+ (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) + b;
}

template<typename T>
Polynomial<T> operator+ (const Polynomial<T> a, const T& b) {
    return a + Polynomial<T>(b);
}

template<typename T>
Polynomial<T> operator- (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) - b;
}

template<typename T>
Polynomial<T> operator- (const Polynomial<T> a, const T& b) {
    return a - Polynomial<T>(b);
}

template<typename T>
Polynomial<T> operator* (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) * b;
}

template<typename T>
Polynomial<T> operator* (const Polynomial<T> a, const T& b) {
    return a * Polynomial<T>(b);
}

template<typename T>
ostream& operator<< (ostream& os, const Polynomial<T> a) {
    if (a.Degree() < 1) return os << a[0];
    bool first = true;
    for (int i = a.Degree(); i >= 0; --i) {
        if (a[i] == T(0)) continue;
        if (!first && a[i] > T(0)) os << '+';
        if (i == 0 || (a[i] != T(-1) && a[i] != T(1))) {
            os << a[i];
            if (i > 0) os << '*';
        } else if (i > 0 && a[i] == T(-1)) {
            os << '-';
        }
        if (i > 0) os << 'x';
        if (i > 1) os << '^' << i;
        first = false;
    }
    return os;
}

template<typename T>
Polynomial<T> operator& (const Polynomial<T>& a, const T& b) {
    return a & Polynomial<T>(b);
}

template<typename T>
Polynomial<T> operator& (const T& a, const Polynomial<T>& b) {
    return Polynomial<T>(a) & b;
}