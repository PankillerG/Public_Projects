template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (first == last) {
        return last;
    }
    Iter ans = first;
    while (first != last) {
        if (!(*first == *ans)) {
            ans++;
            *ans = *first;
        }
        first++;
    }
    ans++;
    return ans;
}
