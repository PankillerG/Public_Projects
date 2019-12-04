#include "writer.h"
#include <memory>

class BufferedWriter: public Writer {
 private:
    char * ptr;
    size_t count_of_bytes, count_of_using = 0;

 public:
    BufferedWriter(size_t buff) {
        ptr = new char[buff];
        count_of_bytes = buff;
    }
    ~BufferedWriter() {
        Writer::Write(ptr, count_of_using);
        delete [] ptr;
    }

    void Write(const char * data,
               size_t buff) {
        size_t i = 0;
        while (i != buff) {
            if (count_of_using == count_of_bytes) {
                Writer::Write(ptr, count_of_bytes);
                count_of_using = 0;
            }
            ptr[count_of_using] = data[i];
            count_of_using++;
            i++;
        }
    }
};
