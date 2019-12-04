#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
T fast_pow(T a, size_t n, vector<T>& cache) {
    if (n == 0) return T(1);
    if (cache.size() <= n) cache.resize(n+1);
    if (cache[n] != T(0)) return cache[n];
    if (a == T(0)) return a;
    if (n == 1) {
        cache[n] = a;
        return a;
    }
    if (n % 2 == 0) {
        cache[n] = fast_pow(a, n / 2, cache) * fast_pow(a, n / 2, cache);
    } else {
        cache[n] = fast_pow(a, n - 1, cache) * a;
    }
    return cache[n];
}

template<typename T>
T abs(const T& a) {
    if (a >= T(0)) return a;
    return a * T(-1);
}

template <typename T>
class Polynomial {
 private:
    map <size_t, T> values;

 public:
    // создающий многочлен по заданному
    // вектору коэффициентов (коэффициенты задаются от младшего к старшим)
    Polynomial(const vector<T>& v) {
        size_t i = 0;
        for (auto& x : v) {
            if (x != T(0)) values[i] = x;
            i++;
        }
        simplify();
    }

    Polynomial(initializer_list<T> list) {
        size_t i = 0;
        for (auto& x : list) {
            if (x != T(0)) values[i] = x;
            i++;
        }
        simplify();
    }

    // создающий многочлен по заданному коэффициенту
    // (многочлен нулевой степени), который
    // по умолчанию равен значению по умолчанию параметра шаблона.
    Polynomial(const T& n) {
        values[0] = n;
        simplify();
    }

    Polynomial() {
        values[0] = T();
        simplify();
    }

    static Polynomial<T> fast_pow_poly(
        const Polynomial<T>& a, size_t n, vector<Polynomial<T>>& cache) {
        if (n == 0) return Polynomial<T>(T(1));
        if (cache.size() <= n) cache.resize(n+1);
        if (cache[n] != Polynomial<T>(T(0))) return cache[n];
        if (a == Polynomial<T>(T(0))) return a;
        if (n == 1) {
            cache[n] = a;
            return a;
        }
        if (n % 2 == 0) {
            cache[n] = fast_pow_poly(a, n / 2, cache) * fast_pow_poly(a, n / 2, cache);
        } else {
            cache[n] = fast_pow_poly(a, n - 1, cache) * a;
        }
        return cache[n];
    }

    // создающий многочлен по заданным итераторам на начало
    // и следующий за концом последовательности
    // коэффициентов (аналогично, от младшего к старшим).
    template<typename Iterator>
    Polynomial(Iterator begin, Iterator end) {
        size_t i = 0;
        for (auto it = begin; it != end; ++it) {
            if (*it != T(0)) values[i] = *it;
            i++;
        }
    }

    Polynomial<T>& simplify() {
        // values.erase(remove(values.begin(), values.end(), 'a'), values.end())
        vector<size_t> keys_to_erase;
        for (auto&[i, x] : values) {
            if (x == T(0)) keys_to_erase.push_back(i);
        }
        for (auto x : keys_to_erase)
            values.erase(x);
        return *this;
    }

    // Перегрузите операторы == и !=. Ваш код должен быть очень простым.
    // Операторы должны работать и в том случае,
    // когда один из аргументов является скаляром.
    bool operator== (const Polynomial<T>& other) const {
        for (auto&[i, x] : values) {
            if (x != other[i]) return false;
        }
        for (auto&[i, x] : other.values) {
            if (x != (*this)[i]) return false;
        }
        return true;
    }

    bool operator!= (const Polynomial<T>& other) const {
        return !(*this == other);
    }

    // Перегрузите оператор [] для получения коэффициента
    // многочлена перед заданной степенью переменной.
    // Достаточно константной версии этого оператора.
    // Оператор должен работать для любых степеней
    // (в том числе больших текущей максимальной).
    const T operator[] (const size_t& ind) const {
        if (values.count(ind) == 0) return T(0);
        return values.at(ind);
    }

    // Напишите также метод Degree для вычисления степени многочлена
    // (считайте, что у нулевого многочлена степень равна -1).
    int Degree() const {
        int result = -1;
        for (auto&[i, x] : values) {
            if (x != T(0)) result = i;
        }
        return result;
    }

    Polynomial<T>& operator+= (const Polynomial<T>& other) {
        for (auto&[i, x] : other.values) {
            values[i] += x;
        }
        simplify();
        return *this;
    }

    Polynomial<T>& operator-= (const Polynomial<T>& other) {
        for (auto&[i, x] : other.values) {
            values[i] -= x;
        }
        simplify();
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

    using PolynomialIterator = typename map<size_t, T>::const_iterator;

    PolynomialIterator begin() const {
        return values.begin();
    }

    PolynomialIterator end() const {
        return values.end();
    }

    Polynomial<T> operator* (const Polynomial<T>& other) const {
        Polynomial<T> result = T(0);
        for (auto&[i, x] : values) {
            for (auto&[j, y] : other.values) {
                result.values[i+j] += x * y;
            }
        }
        result.simplify();
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
        for (auto&[i, x] : values) {
            if (x != T(0))
                result += x * fast_pow(value, i, cache);
        }
        return result;
    }

    Polynomial<T> operator& (const Polynomial<T>& other) const {
        Polynomial<T> result = T(0);
        vector<Polynomial<T>> cache;
        for (auto&[i, x] : values) {
            if (x != T(0))
                result += x * fast_pow_poly(other, i, cache);
        }
        return result;
    }

    Polynomial<T> operator/ (const Polynomial<T>& other) const {
        Polynomial<T> a = *this;
        Polynomial<T> result = T(0);
        while (a.Degree() >= other.Degree()) {
            Polynomial<T> d = T(0);
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

// Перегрузите операторы == и !=. Ваш код

// должен быть очень простым.
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
