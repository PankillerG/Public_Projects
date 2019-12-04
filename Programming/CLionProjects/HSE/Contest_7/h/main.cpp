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

template <typename T>
ostream& operator << (ostream& os, const Polynomial <T>& other) {
    int deg_now = other.Degree();
    if (deg_now == -1) {
        os << T(0);
        return os;
    }
    if (deg_now == 0) {
        os << other[deg_now];
    } else if (other[deg_now] == T(-1)) {
        os << "-x";
        if (deg_now > 1) {
            os << "^";
            os << deg_now;
        }
    } else if (other[deg_now] == T(1)) {
        os << "x";
        if (deg_now > 1) {
            os << "^";
            os << deg_now;
        }
    } else if (other[deg_now] != T(0)) {
        if (deg_now <= 1) {
            os << other[deg_now];
            os << "*x";
        } else {
            os << other[deg_now];
            os << "*x^";
            os << deg_now;
        }
    }
    deg_now--;
    while (deg_now >= 1) {
        if (other[deg_now] != T(0)) {
            if (other[deg_now] > T(0)) {
                os << "+";
            }
            if (other[deg_now] == T(-1)) {
                os << "-x";
            } else if (other[deg_now] == T(1)) {
                os << "x";
            } else {
                os << other[deg_now];
                os << "*x";
            }
            if (deg_now > 1) {
                os << "^";
                os << deg_now;
            }
        }
        deg_now--;
    }
    if (other[deg_now] != T(0)) {
        if (other[deg_now] > T(0)) {
            os << "+";
        }
        os << other[deg_now];
    }
    return os;
}

int main() {
    vector <int> a  = {1, 2, 3};
    Polynomial all(a);
    cout << all;
    return 0;
}
