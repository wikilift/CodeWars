//! https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4/train/dart
import 'dart:math';

List<int> gap(int g, int m, int n) {
  bool numberIsPrime(int data) {
    if (data < 2) return false;
    for (int i = 2; i <= sqrt(data).toInt(); i++) {
      if (data % i == 0) return false;
    }
    return true;
  }

  int? previousNumber;
  for (int i = m; i <= n; i++) {
    if (numberIsPrime(i)) {
      if (previousNumber != null && i - previousNumber == g) return [previousNumber, i];
      previousNumber = i;
    }
  }
  return [];
}

void main() {
  print(gap(2, 5, 7));
  print(gap(2, 5, 5));
  print(gap(4, 130, 200));
  print(gap(6, 100, 110));
  print(gap(11, 30000, 100000));
}
