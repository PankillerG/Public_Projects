#include <iostream>
#include <string>

class Vim {
 private:
    size_t position = 0;
    std::string text;
    int mode = 0;

 public:
    void cin_char(char temp) {
        if (mode == 0) {
            if (temp == 'h' && position > 0) {
                position--;
            }
            if (temp == 'l' && position < text.size()) {
                position++;
            }
            if (temp == 'i') {
                mode = 1;
            }
        } else {
            text.insert(text.begin() + position, temp);
            position++;
        }
    }

    void esc() {
        mode = 0;
    }

    const std::string& GetText() {
        return text;
    }
};

std::ostream& operator <<(std::ostream& os, Vim& vim_) {
    return os << vim_.GetText();
}

std::istream& operator >>(std::istream& it, Vim& vim_) {
    char ch;
    if (it >> std::noskipws >> ch) {
    if (ch == '<') {
            it >> ch;
            it >> ch;
            it >> ch;
            it >> ch;
            vim_.esc();
        } else {
            vim_.cin_char(ch);
        }
    }
    return it;
}

using namespace std;

int main() {
    Vim vim_;
    while  (cin >> vim_) {}
    cout << vim_;
    cout << "\n";
    return 0;
}
