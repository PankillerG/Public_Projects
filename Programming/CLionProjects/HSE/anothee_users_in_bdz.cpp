namespace my_cstring {
  char * strcat(char * destination, const char * source) {
    while (*destination++) {}
    while (*destination++ += *source++) {}
    *destination = '\0';
    return destination;
    }
};

#include <iostream>

using namespace std;

int main() {
    char s1[100] = "aa";
    char s2[100] = "b";
    cout << my_cstring::strcat(s1, s2);
    return 0;
}
