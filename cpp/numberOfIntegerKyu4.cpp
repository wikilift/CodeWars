//https://www.codewars.com/kata/546d5028ddbcbd4b8d001254/train/python


#include <iostream>
#include <vector>

int partitions(int n) {
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] += dp[j-i];
        }
    }
    return dp[n];
}

int main() {
    std::cout << partitions(5) << std::endl; 
    return 0;
}
