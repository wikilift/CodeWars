//https://www.codewars.com/kata/51b6249c4612257ac0000005/train/dart

int romanToInt(String s) {
  final Map<String, int> romanMap = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000};
  int total = 0, prev = 0;

  for (final c in s.split('')) {
    int curr = romanMap[c]!;
    total += curr;
    if (curr > prev) {
      total -= 2 * prev;
    }
    prev = curr;
  }

  return total;
}

void main() {
  print(romanToInt("MM"));
  print(romanToInt("MDCLXVI"));
  print(romanToInt("M"));
  print(romanToInt("CD"));
  print(romanToInt("XC"));
  print(romanToInt("XL"));
  print(romanToInt("I"));
}
