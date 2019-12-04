#include <forward_list>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

const int maximum_of_n = 3e5 + 1;
int n;
int m;
long long local_1[maximum_of_n * 4];
long long local_2[maximum_of_n * 4];
int local_3_a[maximum_of_n];

typedef long long ll;
std::vector <std::forward_list <long long>> my_vect(maximum_of_n,
                                                    std::forward_list <long long>());
void re_adding(int loc_temp_1,
               int loc_temp_2,
               int loc_temp_3,
               int l,
               int r,
               int d) {
    if (l > loc_temp_3 ||
        loc_temp_2 > r) {
        return;
    }
    if (loc_temp_2 >= l &&
        r >= loc_temp_3) {
        local_1[loc_temp_1] =
            local_1[loc_temp_1] + d;
        return;
    }
    int loc_temp_4;
    loc_temp_4 = (loc_temp_2 + loc_temp_3) / 2;
    re_adding(loc_temp_1 * 2 + 1,
              loc_temp_2,
              loc_temp_4,
              l,
              r,
              d);
    re_adding(loc_temp_1 * 2 + 2,
              loc_temp_4 + 1,
              loc_temp_3,
              l,
              r,
              d);
}

long long getting(int loc_temp_1,
                  int loc_temp_2,
                  int loc_temp_3,
                  int position) {
    if (loc_temp_3 == loc_temp_2) {
        return local_1[loc_temp_1];
    }
    int loc_temp_4;
    loc_temp_4 = (loc_temp_2 + loc_temp_3) / 2;
    if (position > loc_temp_4) {
        return local_1[loc_temp_1] + getting(loc_temp_1 * 2 + 2,
                                             loc_temp_4 + 1,
                                             loc_temp_3,
                                             position);
    } else {
        return local_1[loc_temp_1] + getting(loc_temp_1 * 2 + 1,
                                             loc_temp_2,
                                             loc_temp_4,
                                             position);
    }
}

void decide() {
    for (int i = 2;
         i * i < maximum_of_n;
         i++) {
        for (int j = i;
             i * j < maximum_of_n;
             j++) {
            my_vect[i * j].push_front(i);
        }
    }
    scanf("%d",
          &n);
    for (size_t i = 0;
         i < n;
         i++) {
        scanf("%lld",
              &local_3_a[i]);
    }
    scanf("%d",
          &m);
    for (size_t i = 0;
         i < m;
         i++) {
        int local_1;
        scanf("%d",
              &local_1);
        if (local_1 != 1) {
            long long d;
            int l;
            int r;
            scanf("%d%d%lld",
                  &l,
                  &r,
                  &d);
            l--;
            r--;
            re_adding(0,
                      0,
                      n,
                      l,
                      r,
                      d);
        } else {
            long long cc;
            scanf("%lld",
                  &cc);
            long long sum;
            sum = local_3_a[cc - 1];
            for (auto elem : my_vect[cc]) {
                sum = sum + getting(0,
                                    0,
                                    n,
                                    elem - 1);
                if ((cc / elem) != elem) {
                    sum = sum + getting(0,
                                        0,
                                        n,
                                        (cc / elem) - 1);
                }
            }
            sum = sum + getting(0,
                                0,
                                n,
                                cc - 1);
            if (cc != 1) {
                sum = sum + getting(0,
                                    0,
                                    n,
                                    0);
            }
            printf("%lld\n",
                   sum);
        }
    }
}

int main() {
    decide();
    return 0;
}
