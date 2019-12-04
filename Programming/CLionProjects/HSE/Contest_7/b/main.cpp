#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
 private:
    vector <vector <T>> matr;

 public:
    Matrix(const std::vector<std::vector<T>>& input) {
        matr = input;
    }

    pair<size_t, size_t> size() const {
        return make_pair(matr.size(), matr[0].size());
    }

    const vector <T>& operator[](size_t temp) const {
        return matr[temp];
    }
    vector <T>& operator[](size_t temp) {
        return matr[temp];
    }

    const Matrix& operator +=(const Matrix& other) {
        for (size_t i = 0; i < matr.size(); i++) {
            for (size_t j = 0; j < matr[0].size(); j++) {
                matr[i][j] += other[i][j];
            }
        }
        return *this;
    }

    Matrix operator +(const Matrix& other) const {
        Matrix ans = matr;
        ans += other;
        return ans;
    }

    const Matrix& operator *=(const T& other) {
        for (size_t i = 0; i < matr.size(); i++) {
            for (size_t j = 0; j < matr[0].size(); j++) {
                matr[i][j] *= other;
            }
        }
        return *this;
    }

    Matrix operator *(const T& other) const {
        Matrix ans = matr;
        ans *= other;
        return ans;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& m) {
    for (size_t i = 0; i < m.size().first; i++) {
        for (size_t j = 0; j <  m.size().second; j++) {
            if (j + 1 !=  m.size().second) {
                out << m[i][j] << "\t";
            } else if (j + 1 ==  m.size().second && i + 1 != m.size().first) {
                out << m[i][j] << "\n";
            } else {
                out << m[i][j];
            }
        }
    }
    return out;
}

int main() {
    vector <vector <double>> all;
    vector <double> local {1, 2, 3, 4, 5};
    for (size_t i = 0; i < 3; i++) {
        all.push_back(local);
    }
    Matrix a(all);
    cout << a << "\n";
    Matrix b(a);
    cout << "\n" << b << "\n";
    cout << "\n" << a + b << "\n";
    Matrix g = a + b;
    cout << "\n" << g << "\n";
    a += b;
    cout << "\n" << a << "\n";
    cout << "\n" << a * 2 << "\n";
    Matrix c = a * 2;
    cout << "\n" << c << "\n";
    cout << "\n" << a << "\n";
    a *= 0.3;
    cout << "\n" << a << "\n";
    return 0;
}
