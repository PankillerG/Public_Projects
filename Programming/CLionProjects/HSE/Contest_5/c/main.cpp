#include <algorithm>
#include <vector>

template <typename T>
void process(const std::vector<T>& data) {
    std::vector<T> filtered;
    filtered.resize(data.size());
    auto filtered_last = std::copy_if(
        data.begin(),
        data.end(),
        filtered.begin(),
        [](const T& x) { return x > 0; });

    print_results(filtered.begin(), filtered_last);
}
