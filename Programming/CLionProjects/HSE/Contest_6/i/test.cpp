int ans1 = days;
int y;
int m;
for (size_t i = 1970; i <= 2099; ++i) {
    int qwe = 365;
    if (is_vis(i)) {
        qwe = 366;
    }
    if (ans1 - qwe > 0) {
        ans1 -= qwe;
    } else {
        y = i;
        break;
    }
}
vector<int> asd = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
if (is_vis(y)) {
    asd[1] = 29;
}
for (size_t i = 0; i < 12; ++i) {
    if (ans1 - asd[i] > 0) {
        ans1 -= asd[i];
    } else {
        m = i + 1;
        break;
    }
}
