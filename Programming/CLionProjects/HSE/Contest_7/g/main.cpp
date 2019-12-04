#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Polynomial {
 private:
    vector <T> data_vect;

 public:
    Polynomial <T> (const vector <T>& input) {
        data_vect = input;
    }

    Polynomial <T> (const T& input = T(0)) {
        vector <T> temp;
        temp.push_back(input);
        data_vect = temp;
    }

    template <typename Iter>
    Polynomial <T> (Iter first, Iter last) {
        vector <T> temp;
        while (first != last) {
            temp.push_back(*first);
            first++;
        }
        data_vect = temp;
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

    Polynomial <T>& operator += (const Polynomial <T>& other) {
        vector <T> answer;
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
            answer[i] += other.data_vect[i];
        }
        data_vect = answer;
        return *this;
    }

    Polynomial <T>& operator += (const T& other) {
        data_vect[0] += other;
        return *this;
    }

    Polynomial <T>& operator -= (const Polynomial <T>& other) {
        vector <T> answer;
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
        data_vect = answer;
        return *this;
    }

    Polynomial <T>& operator -= (const T& other) {
        data_vect[0] -= other;
        return *this;
    }

    const T operator[] (size_t deg) const {
        vector <T> temp;
        temp.resize(1);
        if (deg < 0 || deg >= data_vect.size()) {
            return temp[0];
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
};

template <typename T>
bool operator == (const T& first,
                  const Polynomial <T>& second) {
    return second == first;
}

template <typename T>
bool operator != (const T& first,
                  const Polynomial <T>& second) {
    return !(second == first);
}

template <typename T>
Polynomial <T> operator + (const T& first,
                           const Polynomial <T>& second) {
    Polynomial <T> answer(second.data_vect);
    answer.data_vect += first;
    return answer;
}

template <typename T>
Polynomial <T> operator - (const T& first,
                           const Polynomial <T>& second) {
    Polynomial <T> answer(second.data_vect);
    answer.data_vect -= first;
    return answer;
}

int main() {
    vector <int> all(1);
    all[0] = 1;
    Polynomial a(all);
    Polynomial b(all);
    if (a == b) {
        cout << 1;
    }
    a = a + b;
    return 0;
}
