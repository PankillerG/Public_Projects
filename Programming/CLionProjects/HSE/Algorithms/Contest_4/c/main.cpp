#include <algorithm>
#include <iostream>

const int maximum_of_n = 1e5 + 1;
long long local_1[maximum_of_n * 4];
long long local_2[maximum_of_n];
int n;
int m;

struct my_point {
    long long left;
    long long right;
    bool kind_of;
};
my_point point_t_[maximum_of_n * 4];

void adding(int loc_temp_1,
          int loc_temp_2,
          int loc_temp_3) {
    if (local_1[loc_temp_1] != -1) {
        point_t_[loc_temp_1] = {local_1[loc_temp_1],
                local_1[loc_temp_1],
                true};
        if (loc_temp_2 != loc_temp_3) {
            local_1[2 * loc_temp_1] =
            local_1[2 * loc_temp_1 + 1] =
            local_1[loc_temp_1];
        }
        local_1[loc_temp_1] = -1;
    }
}

void re_adding(int loc_temp_1,
            int loc_temp_2,
            int loc_temp_3,
            int l,
            int r,
            long long color) {
    adding(loc_temp_1,
         loc_temp_2,
         loc_temp_3);
    if (l > r) {
        return;
    }
    if (loc_temp_2 == l &&
        loc_temp_3 == r) {
            local_1[loc_temp_1] = color;
            adding(loc_temp_1,
            loc_temp_2,
            loc_temp_3);
            return;
    }

    int loc_temp_4;
    loc_temp_4 = (loc_temp_2 + loc_temp_3) >> 1;
    re_adding(loc_temp_1 * 2,
           loc_temp_2,
           loc_temp_4,
           l,
           std::min(loc_temp_4, r),
           color);
    re_adding(loc_temp_1 * 2 + 1,
           loc_temp_4 + 1,
           loc_temp_3,
           std::max(loc_temp_4 + 1, l),
           r,
           color);
    point_t_[loc_temp_1].left =
        point_t_[2 * loc_temp_1].left;
    point_t_[loc_temp_1].right =
        point_t_[2 * loc_temp_1 + 1].right;
    if (point_t_[2 * loc_temp_1].kind_of &&
        point_t_[2 * loc_temp_1 + 1].kind_of &&
        point_t_[2 * loc_temp_1].right <=
                point_t_[2 * loc_temp_1 + 1].left) {
            point_t_[loc_temp_1].kind_of = true;
    } else {
        point_t_[loc_temp_1].kind_of = false;
    }
}

void making(int loc_temp_1,
           int loc_temp_2,
           int loc_temp_3) {
    if (loc_temp_2 != loc_temp_3) {
        int loc_temp_4;
        loc_temp_4 =
        (loc_temp_2 + loc_temp_3)
        >> 1;
        making(loc_temp_1 * 2,
              loc_temp_2,
              loc_temp_4);
        making(loc_temp_1 * 2 + 1,
              loc_temp_4 + 1,
              loc_temp_3);
        point_t_[loc_temp_1].left =
            point_t_[2 * loc_temp_1].left;
        point_t_[loc_temp_1].right =
            point_t_[2 * loc_temp_1 + 1].right;
        if (point_t_[2 * loc_temp_1].kind_of &&
            point_t_[2 * loc_temp_1 + 1].kind_of &&
            point_t_[2 * loc_temp_1].right <=
                    point_t_[2 * loc_temp_1 + 1].left) {
                point_t_[loc_temp_1].kind_of = true;
        } else {
            point_t_[loc_temp_1].kind_of = false;
        }
        local_1[loc_temp_1] = -1;
    } else {
        point_t_[loc_temp_1] = {local_2[loc_temp_2],
                local_2[loc_temp_2],
                true};
        local_1[loc_temp_1] = -1;
    }
}

my_point getting(int loc_temp_1,
             int loc_temp_2,
             int loc_temp_3,
             int l,
             int r) {
    adding(loc_temp_1,
         loc_temp_2,
         loc_temp_3);
    if (l > r) {
        return {-1,
                -1,
                true};
    }
    if (loc_temp_2 == l &&
        loc_temp_3 == r) {
            return point_t_[loc_temp_1];
    }

    int loc_temp_4;
    loc_temp_4 =
    (loc_temp_2 + loc_temp_3)
    >> 1;
    my_point point_q = getting(loc_temp_1 * 2,
                       loc_temp_2,
                       loc_temp_4,
                       l,
                       std::min(loc_temp_4, r));
    my_point point_a = getting(loc_temp_1 * 2 + 1,
                       loc_temp_4 + 1,
                       loc_temp_3,
                       std::max(loc_temp_4 + 1, l),
                       r);
    if (point_q.kind_of &&
        point_a.kind_of &&
        (point_q.right <= point_a.left ||
            point_q.right == -1 ||
            point_a.left == -1)) {
        return {point_q.left,
                point_a.right,
                true};
    } else {
        return {point_q.left,
                point_a.right,
                false};
    }
}

void decide() {
    std::cin >> n
             >> m;
    for (size_t i = 0;
         i < n;
         i++) {
        std::cin >> local_2[i];
    }
    making(1,
          0,
          n - 1);
    for (size_t i = 0;
         i < m;
         i++) {
        int point_t_;
        int l;
        int r;
        std::cin >> point_t_
                 >> l
                 >> r;
        l--;
        r--;
        if (point_t_ != 1) {
            if (getting(1,
                    0,
                    n - 1,
                    l,
                    r).kind_of) {
                std::cout << "Yes"
                          << "\n";
            } else {
                std::cout << "No"
                          << "\n";
            }
        } else {
            long long cc;
            std::cin >> cc;
            re_adding(1,
                   0,
                   n - 1,
                   l,
                   r,
                   cc);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    decide();
    return 0;
}