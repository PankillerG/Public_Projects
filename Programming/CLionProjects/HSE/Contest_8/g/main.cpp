#include <iostream>

class C {
public:
    C() {
        std::cout << "constructor C()\n";
    }

    C(const C& other) {
        std::cout << "constructor C(const C&)\n";
    }

    C(C&& other) {
        std::cout << "constructor C(const C&&)\n";
    }

    C& operator = (const C& other) {
        std::cout << "operator = (const C&)\n";
        return *this;
    }

    C& operator = (C&& other) {
        std::cout << "operator = (const C&&)\n";
        return *this;
    }

    ~C() {
        std::cout << "destructor C()\n";
    }
};

class D {
 private:
    C c1;
    const C& c2;
    const C* c3;

 public:
    D(const C& arg1, const C& arg2, const C* arg3):
        c1(arg1),
        c2(arg2),
        c3(arg3)
    {
        std::cout << "constructor D(const C&, const C&, const C*)\n";
    }

    ~D() {
        std::cout << "destructor D()\n";
    }
};

int main() {
    C a;
    D d(a, a, &a);
    D dd = d;
    return 0;
}
