//https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/dart

BigInt height(int n, int m) {
  if (n == 0 || m == 0) return BigInt.zero;

  BigInt result = BigInt.zero;
  BigInt comb = BigInt.one;

  for (int i = 1; i <= n && i <= m; i++) {
    comb = comb * BigInt.from(m - i + 1) ~/ BigInt.from(i);
    result += comb;
  }
  return result;
}

//python
