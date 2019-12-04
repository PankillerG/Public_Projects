#include <iostream>

class TimeLogger {
 private:
    long starter;

 public:
    TimeLogger() {
        starter = Now();
    }

    ~TimeLogger() {
        std::cout << (Now() - starter);
        std::cout << " milliseconds";
        std::cout << "\n";
    }
};
