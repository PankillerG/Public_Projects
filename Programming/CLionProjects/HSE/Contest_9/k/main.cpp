#include <iostream>
#include <memory>
#include <string>
#include "tokenizer.h"

class My_Callback: public CallbackBase {
 private:
    size_t ptr;
    int answer;

 public:
    My_Callback() {
        ptr = 0, answer = 0;
    }

    std::pair <int, size_t> do_pair() const {
        return std::make_pair(answer, ptr);
    }

    void OnToken(const char* token,
                 size_t size) override {
        if (ptr < size) ptr = size;
        ++answer;
    }
};

int main() {
    std::string str;
    std::getline(std::cin, str);
    Tokenizer str_tokenizer;
    My_Callback temp;
    str_tokenizer.Tokenize(str, &temp);
    std::cout << temp.do_pair().first <<
                 " " <<
                 temp.do_pair().second <<
                 "\n";
    return 0;
}
