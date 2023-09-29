//https://www.codewars.com/kata/5279f6fe5ab7f447890006a7/train/cpp
#include <iostream>
#include <vector>

struct PeakData {
  std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &arr) {
    PeakData result;
    for (std::size_t i = 1, j; i < arr.size(); ++i) {
        if (arr[i] > arr[i-1]) {
            for (j = i; j < arr.size() && arr[j] == arr[i]; ++j);
            if (j < arr.size() && arr[j] < arr[i]) {
                result.pos.push_back(i);
                result.peaks.push_back(arr[i]);
            }
            i = j - 1;
        }
    }
    return result;
}

int main() {
    std::vector<int> arr = {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3};
    PeakData result = pick_peaks(arr);
    
    // Output the results
    std::cout << "Positions: ";
    for (int p : result.pos) std::cout << p << ' ';
    std::cout << "\nPeaks: ";
    for (int p : result.peaks) std::cout << p << ' ';
    std::cout << std::endl;

    return 0;
}
