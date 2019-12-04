#include <cstddef>  // for size_t

class RangeError {
};

size_t CountValues(const char * data, size_t size) {
    size_t answer = 0, byte_now = 0, size_of_block = 0;
    char * size_of_block_str = reinterpret_cast<char*>(&size_of_block);
    while (size > byte_now) {
        if ((sizeof(size_of_block) +
             byte_now) > size) {
            throw RangeError();
        }
        for (size_t i = 0;
             i < sizeof(size_of_block);
             i++) {
            size_of_block_str[i] = data[byte_now + i];
        }
        byte_now = byte_now + sizeof(size_of_block);
        if ((size_of_block +
             byte_now) > size) {
            throw RangeError();
        }
        byte_now = byte_now + size_of_block;
        answer++;
    }
    return answer;
}
