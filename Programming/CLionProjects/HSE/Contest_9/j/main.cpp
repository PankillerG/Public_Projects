#include <cstddef>

template <typename T>
class IntegrationMethod {
 public:
    IntegrationMethod() {}

    virtual double Integrate(T function,
                             double x,
                             double y,
                             int n)
                             const = 0;
};

template <typename T>
class RectangleRule: public IntegrationMethod <T> {
 public:
    double Integrate(T function,
                     double x,
                     double y,
                     int n) const {
        double answer = 0, xk = x;
        for (size_t i = 0;
             i < n;
             i++) {
            auto temp = (function((2 * xk + (y - x) / n) / 2) * ((y - x) / n));
            answer += temp;
            xk += ((y - x) / n);
        }
        return answer;
    }
};

template <typename T>
class TrapezoidalRule: public IntegrationMethod <T> {
 public:
    double Integrate(T function,
                     double x,
                     double y,
                     int n) const {
        double answer = 0, xk = x;
        for (size_t i = 0;
             i < n;
             i++) {
            auto temp = (((function(xk) + function(xk + (y - x) / n)) / 2));
            temp *= ((y - x) / n);
            answer += temp;
            xk += ((y - x) / n);
        }
        return answer;
    }
};
