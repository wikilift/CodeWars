//! https://www.codewars.com/kata/54b058ce56f22dc6fe0011df/train/dart

int cutLog(List<int> p, int n) {
  List<int> revenue = List<int>.filled(n + 1, 0);

  for (int j = 1; j <= n; j++) {
    revenue[j] = List.generate(j, (i) => p[i + 1] + revenue[j - i - 1]).reduce((a, b) => a > b ? a : b);
  }

  return revenue[n];
}

void main() {
  List<int> p = [0, 1, 5, 8, 9, 10];
  int n = 5;
  print('Maximum revenue for length $n is ${cutLog(p, n)}');
}
