#include<iostream>
#include<string>

class Serializer {
 public:
    virtual void EndArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void BeginArray() = 0;
};

class JsonSerializer : public Serializer {
 private:
    int count;
    std::string my_string;

 public:
    JsonSerializer() : count(0) {}

    void EndArray() {
        auto temp = my_string.size() - 1;
        count--;
        if (my_string[temp] != '[') my_string.pop_back();
        my_string = my_string + ']' + ',';
        if (count == 0) {
            my_string.pop_back();
            std::cout << my_string;
            my_string = "";
        }
    }

    void AddArrayItem(const std::string &s) {
        my_string = my_string + '"' + s + '"' + ',';
    }

    void BeginArray() {
        count++;
        my_string = my_string + '[';
    }
};
