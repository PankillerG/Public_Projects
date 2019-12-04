#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename T>
T new_pow(
    T num,
    size_t deg,
    vector <T>& temp
    ) {
    if (deg == 0) {
        return T(1);
    }
    if (temp.size() <= deg) {
        temp.resize(deg + 1);
    }
    if (temp[deg] != T(0)) {
        return temp[deg];
    }
    if (num == T(0)) {
        return num;
    }
    if (deg == 1) {
        temp[deg] = num;
        return num;
    }
    if (deg % 2 != 0) {
        temp[deg] = new_pow(num, deg - 1, temp) *
                    num;
    } else {
        temp[deg] = new_pow(num, deg / 2, temp) *
                    new_pow(num, deg / 2, temp);
    }
    return temp[deg];
}


template <typename T>
class Polynomial {
 private:
    map <size_t, T> data_map;

 public:
    Polynomial(const vector <T>& input) {
        size_t i = 0;
        for (auto & el : input) {
            if (el != T(0)) {
                data_map[i] = el;
            }
            i++;
        }
        clear_zero();
    }

    Polynomial(const T& input = T(0)) {
        data_map[0] = input;
        clear_zero();
    }

    template <typename Iter>
    Polynomial(Iter first, Iter last) {
        size_t i = 0;
        for (auto it = first;
             it != last;
             it++) {
            if (*it != T(0)) {
                data_map[i] = *it;
            }
            i++;
        }
    }

    Polynomial <T>& clear_zero() {
        vector <size_t> temp;
        for (auto & [i, el] : data_map) {
            if (el == T(0)) {
                temp.push_back(i);
            }
        }
        for (auto el : temp)
            data_map.erase(el);
        return *this;
    }

     static Polynomial <T> new_pow_p(
         const Polynomial <T>& num,
         size_t deg,
         vector <Polynomial <T>>& temp) {
        if (deg == 0) {
            return Polynomial<T>(T(1));
        }
        if (temp.size() <= deg) {
            temp.resize(deg + 1);
        }
        if (temp[deg] != Polynomial<T>(T(0))) {
            return temp[deg];
        }
        if (num == Polynomial <T> (T(0))) {
            return num;
        }
        if (deg == 1) {
            temp[deg] = num;
            return num;
        }
        if (deg % 2 != 0) {
            temp[deg] = new_pow_p(num, deg - 1, temp) * num;
        } else {
            temp[deg] = new_pow_p(num, deg / 2, temp) *
                        new_pow_p(num, deg / 2, temp);
        }
        return temp[deg];
    }


    Polynomial <T> operator + (const Polynomial <T>& other) const {
        Polynomial <T> answer = *this;
        for (auto & [i, el] : other.data_map) {
            answer.data_map[i] += el;
        }
        answer.clear_zero();
        return answer;
    }

    Polynomial <T> operator - (const Polynomial <T>& other) const {
        Polynomial <T> answer = *this;
        for (auto & [i, el] : other.data_map) {
            answer.data_map[i] -= el;
        }
        answer.clear_zero();
        return answer;
    }

    Polynomial <T>& operator += (const Polynomial& other) {
        *this = *this + other;
        return *this;
    }
    Polynomial <T>& operator += (const T& other) {
        Polynomial<T> temp(other);
        *this = *this + temp;
        return *this;
    }

    Polynomial <T>& operator -= (const Polynomial& other) {
        *this = *this - other;
        return *this;
    }
    Polynomial <T>& operator -= (const T& other) {
        Polynomial<T> temp(other);
        *this = *this - temp;
        return *this;
    }

    bool operator == (const Polynomial& other) const {
        for (auto & [i, el] : data_map) {
            if (el != other[i]) {
                return false;
            }
        }
        for (auto & [i, el] : other.data_map) {
            if (el != (*this)[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator == (const T& other) const {
        Polynomial <T> P_other(other);
        return *this == P_other;
    }

    bool operator != (const Polynomial <T>& other) const {
        return !(*this == other);
    }
    bool operator != (const T& other) const {
        return !(*this == other);
    }

    const T operator[] (size_t deg) const {
        if (data_map.count(deg) == 0) {
            return T(0);
        }
        return data_map.at(deg);
    }

    int Degree() const {
        int deg = -1;
        for (auto & [i, el] : data_map) {
            if (el != T(0)) {
                deg = i;
            }
        }
        return deg;
    }

    using PIterator = typename map <size_t, T> ::const_iterator;

    PIterator begin() const {
        return data_map.begin();
    }

    PIterator end() const {
        return data_map.end();
    }

    Polynomial<T> operator * (const Polynomial& other) const {
        Polynomial <T> answer = T(0);
        for (auto & [i, el] : data_map) {
            for (auto & [j, el2] : other.data_map) {
                answer.data_map[i + j] += (el * el2);
            }
        }
        answer.clear_zero();
        return answer;
    }
    Polynomial<T> operator * (const T& other) const {
        Polynomial <T> P_other(other);
        return *this * P_other;
    }

    Polynomial <T>& operator *= (const Polynomial& other) {
        *this = *this * other;
        return *this;
    }
    Polynomial <T>& operator *= (const T& other) {
        Polynomial <T> temp(other);
        *this = *this * temp;
        return *this;
    }

    T operator() (const T& x) const {
        T answer = T(0);
        vector <T> temp;
        for (auto & [i, el] : data_map) {
            if (el != T(0))
                answer += el *
                          new_pow(x,
                                  i,
                                  temp);
        }
        return answer;
    }

    Polynomial <T> operator & (const Polynomial <T> & x) const {
        Polynomial <T> answer = T(0);
        vector <Polynomial <T>> temp;
        for (auto & [i, el] : data_map) {
            if (el != T(0))
                answer += el *
                          new_pow_p(x,
                                    i,
                                    temp);
        }
        return answer;
    }


    Polynomial <T> operator / (const Polynomial <T>& other) const {
        Polynomial <T> answer = T(0);
        Polynomial <T> first = *this;
        while (other.Degree() <= first.Degree()) {
            Polynomial <T> temp = T(0);
            temp.data_map[first.Degree() -
                          other.Degree()] =
                          T(1);
            temp *= first[first.Degree()] /
                          other[other.Degree()];
            answer = answer + temp;
            first -= (temp * other);
        }
        return answer;
    }



    Polynomial <T> operator % (const Polynomial <T>& other) const {
        Polynomial <T> answer = T(0);
        Polynomial <T> first = *this;
        while (other.Degree() <= first.Degree()) {
            Polynomial <T> temp = T(0);
            temp.data_map[first.Degree() -
                          other.Degree()] =
                          T(1);
            temp *= first[first.Degree()] /
                          other[other.Degree()];
            answer = answer + temp;
            first -= (temp * other);
        }
        return first;
    }


    Polynomial <T>& loc_local() {
        auto it = (*this)[Degree()];
        Polynomial <T> other(it);
        return *this = *this / other;
    }

    Polynomial <T> operator , (const Polynomial <T>& other) const {
        Polynomial <T> temp;
        Polynomial <T> first = *this;
        Polynomial <T> second = other;
        while (second.Degree() != -1) {
            first = first % second;
            temp = first;
            first = second;
            second = temp;
        }
        if (first.Degree() != -1) {
            first.loc_local();
        }
        return first;
    }
};

template <typename T>
Polynomial <T> operator + (const T& first, const Polynomial<T>& second) {
    return second + first;
}

template <typename T>
Polynomial<T> operator - (const T& first, const Polynomial <T>& second) {
    return (second - first) * T(-1);
}

template <typename T>
bool operator == (const T& first, const Polynomial <T>& second) {
    return second == first;
}

template <typename T>
bool operator != (const T& first, const Polynomial <T>& second) {
    return second != first;
}

template <typename T>
Polynomial <T> operator * (const T& first, const Polynomial <T>& second) {
    return second * first;
}

template<typename T>
ostream& operator << (ostream& os, const Polynomial<T> other) {
    bool flag = true;
    if (other.Degree() < 1) {
        return os << other[0];
    }
    for (int i = other.Degree();
         i >= 0;
         i--) {
        if (other[i] == T(0)) {
            continue;
        }
        if (!flag && other[i] > T(0)) {
            os << '+';
        }
        if (i == 0 ||
            (other[i] != T(-1)
             && other[i] != T(1))) {
            os << other[i];
            if (i > 0) {
                os << '*';
            }
        } else if (i > 0 &&
                   other[i] == T(-1)) {
            os << '-';
        }
        if (i > 0) {
            os << 'x';
        }
        if (i > 1) {
            os << '^' << i;
        }
        flag = false;
    }
    return os;
}


int main() {
    vector <int> a  = {1, 2, 3};
    Polynomial all(a);
    cout << all;
    return 0;
}

