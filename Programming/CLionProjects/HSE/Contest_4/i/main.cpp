#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack <char> chars;
    string s;
    cin >> s;
    for (auto c : s) {
        if (chars.size() == 0) {
            chars.push(c);
        } else {
            if (c == '(' || c == '[' || c == '{') {
                chars.push(c);
            } else {
                if (c == ')') {
                    if (chars.top() == '(') {
                        chars.pop();
                    } else {
                        chars.push(c);
                    }
                }
                if (c == ']') {
                    if (chars.top() == '[') {
                        chars.pop();
                    } else {
                        chars.push(c);
                    }
                }
                if (c == '}') {
                    if (chars.top() == '{') {
                        chars.pop();
                    } else {
                        chars.push(c);
                    }
                }
            }
        }
    }
    if (chars.size() == 0) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
