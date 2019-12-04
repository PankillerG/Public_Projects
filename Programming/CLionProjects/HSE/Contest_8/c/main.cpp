namespace my_cstring {
    int strcmp(const char * s1, const char * s2) {
        while (*s1 != 0 && *s2 != 0) {
            if (*s1 > *s2) {
                return 1;
            } else if (*s1 < *s2) {
                return -1;
            } else {
                s1++;
                s2++;
            }
        }
        if (*s1 != 0 && *s2 == 0) {
            return 1;
        } else if (*s1 == 0 && *s2 == 0) {
            return 0;
        } else {
            return -1;
        }
    }
}

#include <iostream>

using namespace std;

int main() {
    char s1[100] = "aab";
    char s2[100] = "aaba";
    cout << my_cstring::strcmp(s1, s2);
    return 0;
}
