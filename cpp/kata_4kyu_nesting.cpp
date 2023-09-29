//https://www.codewars.com/kata/520446778469526ec0000001/python
#include <iostream>
#include <vector>

template <typename T>
bool sameStructureAs(const std::vector<T>& a, const std::vector<T>& b);

template <>
bool sameStructureAs<int>(const std::vector<int>& a, const std::vector<int>& b) {
    return a.size() == b.size();
}

template <typename T>
bool sameStructureAs(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (!sameStructureAs(a[i], b[i])) return false;
    }
    return true;
}

int main() {
    std::vector<int> a1 = {1, 1, 1};
    std::vector<int> b1 = {2, 2, 2};
    std::cout << std::boolalpha << sameStructureAs(a1, b1) << std::endl;

    std::vector<std::vector<int>> a2 = {{1, 1}, {1}};
    std::vector<std::vector<int>> b2 = {{2, 2}, {2}};
    std::cout << sameStructureAs(a2, b2) << std::endl;

    std::vector<std::vector<int>> a3 = {{1, 1}, {1}};
    std::vector<std::vector<int>> b3 = {{2, 2}, {2, 2}};
    std::cout << sameStructureAs(a3, b3) << std::endl;

    return 0;
}
