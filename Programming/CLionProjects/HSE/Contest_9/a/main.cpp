//#include "c.h"
#include <iostream>
#include <stdexcept>

class C {
 public:
    C() {
        std::cout << "constructor C()\n";
    }
    ~C() {
        std::cout << "destructor C()\n";
    }
    C(const C& other) {
        throw std::runtime_error("error code: 1");
    }
    C operator = (const C& other) {
        throw std::runtime_error("error code: 2");
    }
};

int foo() {
    C x;
    C y = x;
    // ...
}

int main() {
    try {
        foo();
    } catch (const std::runtime_error&) {
        // ...
    }
}