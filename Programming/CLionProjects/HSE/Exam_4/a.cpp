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

#include <deque>

using namespace std;

int main() {
    C first;
    deque <C> a;
    a.resize(2);
    a.pop_front();
    return 0;
}
