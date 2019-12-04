#include <iostream>

class Writer {
 public:
    virtual void Write(const char * data, size_t len) {
        while (len != 0) {
        std::cout << reinterpret_cast<char>(*data);
        ++data;
        --len;
        }
        std::cout << "%_%zalupa_end \n";
    }
};

#include <vector>

class BufferedWriter: public Writer {
 private:
    std::vector <char> all;
    size_t count_of_using = 0;

 public:
    BufferedWriter(size_t i) {
        all.resize(i);
    }
    ~BufferedWriter() {
        if (count_of_using != 0) {
            char temp[count_of_using];
            for (size_t i = 0;
                i < count_of_using;
                i++) {
                temp[i] = all[i];
            }
            Writer local;
            local.Write(temp, count_of_using);
        }
    }

    void Write(const char * data, size_t len) override {
        if (count_of_using + len >= all.size()) {
            while (count_of_using + len >= all.size()) {
                while (count_of_using < all.size()) {
                    all[count_of_using] = *data;
                    count_of_using++;
                    data++;
                    len--;
                }
                count_of_using = 0;
                char temp[all.size()];
                for (size_t i = 0;
                     i < all.size();
                     i++) {
                    temp[i] = all[i];
                }
                Writer local;
                local.Write(temp, all.size());
            }
            while (len > 0) {
                all[count_of_using] = *data;
                data++;
                count_of_using++;
                len--;
            }
        } else {
            while (len > 0) {
                all[count_of_using] = *data;
                data++;
                count_of_using++;
                len--;
            }
        }
    }
};

int main() {
    char test[100] = "test_11";
    BufferedWriter test_BufferedWriter(3);
    test_BufferedWriter.Write(test, 7);
    return 0;
}
