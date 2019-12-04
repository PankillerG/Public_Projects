#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    auto local_end = v.size();
    for (auto it = 0; it != local_end; ++it) {
            v.push_back(v[it]);
        }
}
