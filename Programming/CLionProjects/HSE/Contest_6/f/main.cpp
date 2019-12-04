#include <vector>

using namespace std;

template <typename T>
class Table {
 private:
    size_t row, colum;
    vector <vector <T>> all_table;

 public:
    Table(size_t height, size_t width) {
        row = height;
        colum = width;
        all_table.resize(height);
        for (size_t i = 0; i < height; i++) {
            all_table[i].resize(width);
        }
    }

    const vector <T>& operator[](size_t temp) const {
        return all_table[temp];
    }
    vector <T>& operator[](size_t temp) {
        return all_table[temp];
    }

    void resize(size_t new_row, size_t new_colum) {
        row = new_row;
        colum = new_colum;
        all_table.resize(new_row);
        for (size_t i = 0; i < new_row; i++) {
            all_table[i].resize(new_colum);
        }
    }

    pair <size_t, size_t> size() {
        return make_pair(row, colum);
    }
    const pair <size_t, size_t> size() const {
        return make_pair(row, colum);
    }
};
