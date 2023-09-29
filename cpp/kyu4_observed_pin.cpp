//https://www.codewars.com/kata/5263c6999e0f40dee200059d/train/cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

std::unordered_map<char, std::string> adj = {{'0', "08"}, {'1', "124"}, {'2', "1235"}, {'3', "236"}, {'4', "1457"}, {'5', "24568"}, {'6', "3569"}, {'7', "478"}, {'8', "05789"}, {'9', "689"}};

void get_pins_helper(const std::string& observed, std::string current, std::vector<std::string>& result) {
    if (current.size() == observed.size()) { result.push_back(current); return; }
    for (char adj_digit : adj[observed[current.size()]]) { get_pins_helper(observed, current + adj_digit, result); }
}

std::vector<std::string> get_pins( std::string observed) {
    std::vector<std::string> result; 
    get_pins_helper(observed, "", result);
    return result;
}


int main() {
    std::string observed = "1357";
    std::vector<std::string> result = get_pins(observed);
    for (const std::string& pin : result) {
        std::cout << pin << " ";
    }
    std::cout << std::endl;
    return 0;
}
