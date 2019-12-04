#include <iostream>
#include <vector>

class Model {
 public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sizer = data.size();
    out.write(
        reinterpret_cast<char*>(&sizer),
        sizeof(size_t));
    for (auto elem : data) {
        out.write(
            reinterpret_cast<char*>(&elem),
            sizeof(int));
    }
}

void Model::load(std::istream& in) {
    size_t sz;
    in.read(
        reinterpret_cast<char*>(&sz),
        sizeof(size_t));
    data.resize(sz);
    in.read(
        reinterpret_cast<char*>(&data[0]),
        sizeof(int) * sz);
}

//#include "model.h"

#include <iostream>
#include <sstream>

int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;
    m1.data = {1, 2, 3, 4};

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    Model m2;
    m2.load(ss);

    if (m1.data != m2.data)
        std::cout << "Models differ\n";
}