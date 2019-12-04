#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
class Polynomial {
 private:
    vector<T> data_vect;

    void clear_zero() {
        while (!(data_vect.empty()) &&
               vdata_vect.back() == static_cast<T>(0)) {
            data_vect.pop_back();
        }
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

    const T operator[] (const size_t i) const {
        if (i >= data_vect.size()) {
            return static_cast<T>(0);
        }
        return data_vect[i];
    }

    int Degree() const {
        return static_cast<int>(data_vect.size()) - 1;
    }

    const auto begin() const {
        return data_vect.begin();
    }

    const auto end() const {
        if (data_vect.empty()) {
            return data_vect.end();
        }
        auto find_zero = --data_vect.end();
        while (*find_zero == static_cast<T>(0) && find_zero != data_vect.begin()) {
            --find_zero;
        }
        return ++find_zero;
    }
};

template <typename T>
Polynomial<T> operator- (const T& c, const Polynomial<T>& p) {
    return (p - c);
}

template <typename T>
Polynomial<T> operator+ (const T& c, const Polynomial<T>& p) {
    return (p + c);
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


