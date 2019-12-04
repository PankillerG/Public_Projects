#include <iostream>
#include <cstddef>

namespace my_cstring {
    size_t strlen(const char * s) {
        size_t count = 0, i = 0;
        while (s[i] != '\0') {
            count++;
            i++;
        }
        return count;
    }
}

using namespace std;

int main() {
    char s1[100] = "123";
    cout << my_cstring::strlen(s1);
    return 0;
}
