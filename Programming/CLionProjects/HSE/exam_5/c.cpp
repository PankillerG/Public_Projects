class Figure {
 public:
    Figure() {}
    virtual double Perimeter() const {}
    virtual ~Figure() {}
};

class Triangle : public Figure {
 private:
    double line_1, line_2, line_3;
 public:
    Triangle(double x, double y, double z): line_1(x), line_2(y), line_3(z) {}
    double Perimeter() const {
        return (line_1 + line_2 + line_3);
    }
};

class Rectangle : public Figure {
 private:
    double line_1, line_2;
 public:
    Rectangle(double x, double y): line_1(x), line_2(y) {}
    double Perimeter() const {
        return (2 * (line_1 + line_2));
    }
};

#include <vector>
#include <iostream>

int main() {
    std::vector<Figure*> figures;

    std::string type;
    double val;

    while (std::cin >> type) {
        if (type == "Triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            figures.push_back(new Triangle(a, b, c));
        } else if (type == "Rectangle") {
            int a, b;
            std::cin >> a >> b;
            figures.push_back(new Rectangle(a, b));
        }
    }

    for (Figure * f : figures)
        std::cout << f->Perimeter() << "\n";

    for (Figure * f : figures)
        delete f;
}
