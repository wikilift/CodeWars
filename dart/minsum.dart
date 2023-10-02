//https://www.codewars.com/kata/5a523566b3bfa84c2e00010b/train/dart

int minSum(arr) => (arr..sort()).asMap().entries.fold(0, (sum, e) => sum + e.value * arr[arr.length - e.key - 1]) ~/ 2;

void main() {
  print(minSum([5, 4, 2, 3]));
}
