//https://www.codewars.com/kata/58f58dc3663082a4ba000033/train/cpp
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

struct Point {
    int row, col;
    bool operator==(const Point& other) const { return row == other.row && col == other.col; }
    bool operator!=(const Point& other) const { return !(*this == other); }
    Point operator+(const Point& other) const { return {row + other.row, col + other.col}; }
};

std::wstring dance(const std::wstring &map_str) {
    std::vector<std::wstring> map;
    std::wstring line;
    for (wchar_t c : map_str) {
        if (c == '\n') { map.push_back(line); line.clear(); } 
        else { line += c; }
    }
    if (!line.empty()) map.push_back(line);
    
    Point start = {0, 0};
    for (size_t i = 0; i < map.size(); i++)
        for (size_t j = 0; j < map[i].size(); j++)
            if (map[i][j] == L'S') { start = {static_cast<int>(i), static_cast<int>(j)}; i = map.size(); break; }
    
    std::vector<Point> dirs = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    std::map<wchar_t, int> arrow_to_dir = {{L'→', 0}, {L'↘', 1}, {L'↓', 2}, {L'↙', 3}, {L'←', 4}, {L'↖', 5}, {L'↑', 6}, {L'↗', 7}};
    std::vector<wchar_t> dir_to_arrow = {L'→', L'↘', L'↓', L'↙', L'←', L'↖', L'↑', L'↗'};
    
    auto is_compatible = [](int dir1, int dir2) { 
        int diff = std::abs(dir1 - dir2);
        return diff <= 2 || diff >= 6; 
    };
    
    std::wstring best_path;
    std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
    
    std::function<void(Point, int, std::wstring, std::vector<std::vector<bool>>)> dfs = 
    [&](Point pos, int last_dir, std::wstring path, std::vector<std::vector<bool>> vis) {
        for (int d = 0; d < 8; d++) {
            Point next = pos + dirs[d];
            
            if (next == start && !path.empty()) {
                std::wstring complete_path = path + dir_to_arrow[d];
                if (complete_path.size() > best_path.size()) best_path = complete_path;
                continue;
            }
            
            if (next.row < 0 || next.row >= static_cast<int>(map.size()) || 
                next.col < 0 || next.col >= static_cast<int>(map[next.row].size()) ||
                vis[next.row][next.col] || map[next.row][next.col] == L'S')
                continue;
            
            wchar_t next_arrow = map[next.row][next.col];
            if (arrow_to_dir.count(next_arrow) == 0) continue;
            
            int next_dir = arrow_to_dir[next_arrow];
            
            if ((last_dir != -1 && !is_compatible(last_dir, d)) || !is_compatible(d, next_dir))
                continue;
            
            vis[next.row][next.col] = true;
            dfs(next, next_dir, path + dir_to_arrow[d], vis);
            vis[next.row][next.col] = false;
        }
    };
    
    dfs(start, -1, L"", visited);
    return best_path;
}