template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
    auto it = first;
    bool flag = true;
    while (flag && it != last) {
        if (f(*it)) {
            flag = false;
        }
        it++;
    }
    if (flag) {
        return false;
    } else {
        return true;
    }
}
