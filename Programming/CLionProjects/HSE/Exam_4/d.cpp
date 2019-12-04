#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
 private:
    std::unordered_map<Key, Value> data;

 public:
    void insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void remove(const Key& key) {
        data.erase(key);
    }

    bool find(const Key& key, Value * const value = nullptr) const;
};


// Почему-то не работает...
//template <typename Key, typename Value>
//bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
//    auto it = std::find(data.begin(), data.end(), key);
//    auto val = *it;
//    if (value != nullptr)
//        value = &val;
//    return it != data.end();
//}

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
    for (auto it = data.begin();
         it != data.end();
         it++) {
        if ((*it).first == key) {
            if (value != nullptr) {
                *value = (*it).second;
            }
            return true;
        }
    }
    return false;
}


// Ваша реализация функции KeyValueStorage::find будет вставлена сюда:

// #include "your_version_of_find.h"

#include <string>

int main() {
    KeyValueStorage<std::string, int> kv;
    kv.insert("hello", 42);
    kv.insert("bye", -13);
    int value = 123;
    auto res = kv.find("wrong", &value);  // должно вернуться false, а value не должен меняться
    res = kv.find("bye", &value);  // должно вернуться true, в value должно быть -13
    res = kv.find("hello", nullptr);  // должно вернуться true
}
