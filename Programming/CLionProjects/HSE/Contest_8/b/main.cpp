#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
 private:
    Node root;

 public:
    bool Has(const std::vector<std::string>& node) const;

    void Insert(const std::vector<std::string>& node);

    void Delete(const std::vector<std::string>& node);
};


// Ваш код будет вставлен сюда
// #include "your_code"

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node * r = &root;
    for (auto & el : node) {
        if ((*r).children.count(el) <= 0) {
            return false;
        } else {
            r = &((*r).children.at(el));
        }
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
    Node * r = &root;
    for (auto & el : node) {
        r = &((*r).children[el]);
    }
}

void Tree::Delete(const std::vector<std::string>& node) {
    Node * r = &root;
    for (auto i = node.begin();
         i != node.end();
         i++) {
             auto el = *i;
             if (i != prev(node.end()) &&
                 (*r).children.count(el) > 0) {
                     r = &((*r).children.at(el));
             } else if ((*r).children.count(el) > 0) {
                 (*r).children.erase(el);
                 return;
             }
    }
}
