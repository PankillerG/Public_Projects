#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Polynomial {
 private:
    vector<T> data_vect;

    void clear_zero() {
        while (
            !(data_vect.empty()) && data_vect.back() == static_cast<T>(0))
            data_vect.pop_back();
    }

 public:
    Polynomial(const vector <T>& input) {
        data_vect = input;
        clear_zero();
    }

    Polynomial(const T& input = T(0)) {
        vector <T> temp;
        temp.push_back(input);
        data_vect = temp;
        clear_zero();
    }

    template <typename Iter>
    Polynomial(Iter first, Iter last) {
        vector <T> temp;
        while (first != last) {
            temp.push_back(*first);
            first++;
        }
        data_vect = temp;
        clear_zero();
    }

    Polynomial <T> operator + (const Polynomial <T>& other) const {
        vector <T> answer;
        answer.resize(max(other.data_vect.size(),
                          data_vect.size()));
        for (size_t i = 0;
             i < data_vect.size();
             i++) {
            answer[i] += data_vect[i];
        }
        for (size_t i = 0;
             i < other.data_vect.size();
             i++) {
            answer[i] += other.data_vect[i];
        }
        Polynomial <T> P_answer(answer);
        return P_answer;
    }
    Polynomial <T> operator + (const T& other) const {
        Polynomial <T> answer(data_vect);
        answer.data_vect[0] += other;
        return answer;
    }

    Polynomial <T> operator - (const Polynomial <T>& other) const {
        vector<T> answer;
        answer.resize(max(data_vect.size(),
                          other.data_vect.size()));
        for (size_t i = 0;
             i < data_vect.size();
             i++) {
            answer[i] += data_vect[i];
        }
        for (size_t i = 0;
             i < other.data_vect.size();
             i++) {
            answer[i] -= other.data_vect[i];
        }
        Polynomial <T> P_answer(answer);
        return P_answer;
    }
    Polynomial <T> operator - (const T& other) const {
        Polynomial <T> answer(data_vect);
        answer.data_vect[0] -= other;
        return answer;
    }

    Polynomial <T>& operator += (const Polynomial& other) {
        *this = *this + other;
        clear_zero();
        return *this;
    }
    Polynomial <T>& operator += (const T& other) {
        Polynomial<T> temp(other);
        *this = *this + temp;
        clear_zero();
        return *this;
    }

    Polynomial <T>& operator -= (const Polynomial& other) {
        *this = *this - other;
        clear_zero();
        return *this;
    }
    Polynomial <T>& operator -= (const T& other) {
        Polynomial<T> temp(other);
        *this = *this - temp;
        clear_zero();
        return *this;
    }

    bool operator == (const Polynomial& other) const {
        vector <T> temp;
        temp.resize(1);
        for (size_t i = 0;
             i < min(other.data_vect.size(),
                     data_vect.size());
             i++) {
            if (data_vect[i] != other.data_vect[i]) {
                return false;
            }
        }
        if (data_vect.size() >= other.data_vect.size()) {
            for (size_t i = other.data_vect.size();
                 i < data_vect.size();
                 i++) {
                if (data_vect[i] != temp[0]) {
                    return false;
                }
            }
        } else {
            for (size_t i = data_vect.size();
                 i < other.data_vect.size();
                 i++) {
                if (other.data_vect[i] != temp[0]) {
                    return false;
                }
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
        if (deg >= data_vect.size()) {
            return T(0);
        }
        return data_vect[deg];
    }

    int Degree() const {
        int deg = -1;
        for (size_t i = 0;
             i < data_vect.size();
             i++) {
            if (data_vect[i] != T(0)) {
                deg = i;
            }
        }
        return deg;
    }

    typename vector <T>::const_iterator begin() const {
        return data_vect.begin();
    }

    typename vector <T>::const_iterator end() const {
        return data_vect.end();
    }

    Polynomial<T> operator * (const Polynomial& other) const {
        vector <T> answer;
        answer.resize(
            other.Degree() +
            static_cast<int>(data_vect.size()) +
            1);
        for (size_t i = 0;
             i < data_vect.size();
             i++) {
            for (int j = 0;
                 j <= other.Degree();
                 j++) {
                answer[i + j] += data_vect[i] * other[j];
            }
        }
        return answer;
    }
    Polynomial<T> operator * (const T& other) const {
        Polynomial <T> P_other(other);
        return *this * P_other;
    }

    Polynomial <T>& operator *= (const Polynomial& other) {
        *this = *this * other;
        clear_zero();
        return *this;
    }
    Polynomial <T>& operator *= (const T& other) {
        Polynomial <T> temp(other);
        *this = *this * temp;
        clear_zero();
        return *this;
    }

    T operator() (const T& x) const {
        if (data_vect.empty()) {
            return T(0);
        }
        T answer = data_vect[data_vect.size() - 1];
        for (int i = data_vect.size() - 2;
             i >= 0;
             i--) {
            answer = answer * x;
            answer += data_vect[i];
        }
        return answer;
    }

    Polynomial <T> operator & (const Polynomial <T>& x) const {
        if (data_vect.empty()) {
            return Polynomial (T(0));
        }
        Polynomial answer = data_vect[data_vect.size() - 1];
        for (int i = data_vect.size() - 2;
             i >= 0;
             i--) {
                 answer = data_vect[i] + answer * x;
             }
        return answer;
    }

    Polynomial <T> operator / (const Polynomial <T>& other) const {
        Polynomial <T> answer = T(0);
        Polynomial <T> first = *this;
        while (other.Degree() <= first.Degree()) {
            Polynomial <T> temp = T(0);
            temp.data_vect.resize(
                first.Degree() +
                1);
            temp.data_vect[first.Degree() -
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
            temp.data_vect.resize(
                first.Degree() +
                1);
            temp.data_vect[first.Degree() -
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
