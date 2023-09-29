#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::unordered_map<char, int64_t>> awesome_map;

std::unordered_map<char, int64_t> ss(int l, int r, const std::string& values, const std::string& operators) {
    std::string key = std::to_string(l) + "," + std::to_string(r);
    
    if (awesome_map.find(key) != awesome_map.end()) {
        return awesome_map[key];
    }
    if (l == r) {
        return {{values[l], 1}};
    }
    
    std::unordered_map<char, int64_t> count = {{'t', 0}, {'f', 0}};

    for (size_t i = l; i < r; ++i) {
        auto left = ss(l, i, values, operators);
        auto right = ss(i + 1, r, values, operators);
        char op = operators[i];
        
        for (auto& lv : left) {
            for (auto& rv : right) {
                char res;
                if (op == '&') {
                    res = (lv.first == 't' && rv.first == 't') ? 't' : 'f';
                } else if (op == '|') {
                    res = (lv.first == 't' || rv.first == 't') ? 't' : 'f';
                } else {  
                    res = (lv.first != rv.first) ? 't' : 'f';
                }
                
                count[res] += lv.second * rv.second;
            }
        }
    }
    
    awesome_map[key] = count;
    return count;
}

int64_t solve(const std::string& s, const std::string& ops) {
    awesome_map.clear(); 
    auto result = ss(0, s.size() - 1, s, ops);
    return result['t'];
}

int main() {
    std::string values = "tft";
    std::string operators = "^&";
    std::cout << "Result: " << solve(values, operators) << std::endl;
    return 0;
}
