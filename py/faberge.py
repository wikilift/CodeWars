#https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/dart

def height(n, m):
    if n == 0 or m == 0:
        return 0

    result = 0
    comb = 1

    for i in range(1, min(n, m) + 1):
        comb = comb * (m - i + 1) // i
        result += comb

    return result

