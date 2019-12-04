//#include "c.h"
#include <iostream>
#include <stdexcept>

class C {
 private:
    static int count;
    const int number;

 public:
    ~C() {
        std::cout << "destructor C() " <<
                     number <<
                     "\n";
    }
    C():
    number(++count) {
        if (count > 3) {
            throw std::runtime_error("error code: 1");
        } else {
            std::cout << "constructor C() " <<
                         number <<
                         "\n";
        }
    }
};

int C::count = 0;

int foo() {
    C * array = new C[100];
    // ...
    delete [] array;
}

int main() {
    try {
        foo();
    } catch (const std::runtime_error&) {
        // ...
    }
}
