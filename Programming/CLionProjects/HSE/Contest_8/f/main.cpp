#include <iostream>
class C {
private:
static int counter;
const int id;
public:
C(): id(++counter) {
        std::cout << "constructor C() " << id << "\n";
    }
C(const C& other): id(++counter) {
        std::cout << "constructor C(const C&) " << id << " " << other.id << "\n";
    }
C(const C&& other): id(++counter) {
        std::cout << "constructor C(const C&&) " << id << " " << other.id << "\n";
    }
    C& operator = (const C& other) {
        std::cout << "operator = (const C&) " << id << " " << other.id << "\n";
return *this;
    }
    C& operator = (C&& other) {
        std::cout << "operator = (const C&&) " << id << " " << other.id << "\n";
return *this;
    }
~C() {
        std::cout << "destructor C() " << id << "\n";
    }
};
int C::counter = 0;

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque <C> a;
    a.resize(n);
    for (size_t i = 0; i < n; i++) {
        a.pop_front();
    }
    return 0;
}
