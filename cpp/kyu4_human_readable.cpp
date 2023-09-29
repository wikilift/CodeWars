//https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/cpp
#include <iostream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {
    if (seconds == 0) return "now";
    std::vector<std::pair<int, std::string>> u = {{365 * 24 * 3600, "year"}, {24 * 3600, "day"}, {3600, "hour"}, {60, "minute"}, {1, "second"}};
    std::vector<std::string> p;
    for (auto& unit : u) {
        int v = seconds / unit.first; seconds %= unit.first;
        if (v > 0) p.push_back(std::to_string(v) + " " + unit.second + (v > 1 ? "s" : ""));
    }
    std::string r = p[0];
    for (int i = 1; i < p.size(); ++i) r += i == p.size() - 1 ? " and " : ", ", r += p[i];
    return r;
}

int main() {
    std::cout << format_duration(62) << std::endl;
    std::cout << format_duration(3662) << std::endl;
    return 0;
}
