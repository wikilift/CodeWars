#https://www.codewars.com/kata/546d5028ddbcbd4b8d001254/train/python

def partitions(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i, n + 1):
            dp[j] += dp[j - i]
    return dp[n]