#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "query.h"

const int RESULTS_TO_PRINT = 3;

bool sorter(std::pair<std::string, int>& first,
            std::pair<std::string, int>& second) {
    if (first.second != second.second) {
        if (first.second > second.second) {
            return true;
        } else {
            return false;
        }
    } else {
        if (first.first < second.first) {
            return true;
        } else {
            return false;
        }
    }
}


int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());

        if (q->action == ACTION_COMMIT) {
            login_stats[q->sender_login] += 1;
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(
        login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(),
              stats_vec.end(),
              sorter);

    if (RESULTS_TO_PRINT <= stats_vec.size()) {
        for (int i = 0; i < RESULTS_TO_PRINT; ++i) {
            std::cout <<
            stats_vec[i].first <<
            " " <<
            stats_vec[i].second <<
            "\n";
        }
    } else {
        for (int i = 0; i < stats_vec.size(); ++i) {
            std::cout <<
            stats_vec[i].first
            << " "
            << stats_vec[i].second <<
            "\n";
        }
    }
}
