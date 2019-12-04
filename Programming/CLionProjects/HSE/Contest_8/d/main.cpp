namespace my_cstring {
    char * strcat(char * destination, const char * source) {
        auto it = destination;
        while (*destination != 0) {
            destination++;
        }
        while (*source != 0) {
            *destination = *source;
            destination++;
            source++;
        }
        *destination = '\0';
        return it;
    }
}

#include <iostream>

using namespace std;

int main() {
    char s1[100] = "aa";
    char s2[100] = "";
    cout << my_cstring::strcat(s1, s2);
    return 0;
}
