#include <iostream>

class A {
 public:
    A(int x) {
        std::cout << "Constructor(int): " << x << "\n";
    }
    A(const A&) {
        std::cout << "Copy constructor\n";
    }
    virtual ~A() {
        std::cout << "Destructor\n";
    }
    virtual void foo() const = 0;
};

class B: public A {
 public:
    B(int i = 42) : A(i) {}
    void foo() const override {
        auto ptr = new B(17);
        //std::cout << "A::foo()" << "\n";
        A::foo();
        delete ptr;
    }
};

int main() {
    std::unique_ptr<A> ptr(new B);
    ptr->foo();
}
