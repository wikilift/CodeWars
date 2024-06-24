//https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1/train/dart

int duplicateCount(String text) => text
    .toLowerCase()
    .split('')
    .toSet()
    .where((e) => text.toLowerCase().split('').where((x) => x == e).length > 1)
    .length;

void main() {
  print(duplicateCount("abcde"));
  print(duplicateCount("aabbcde"));
  print(duplicateCount("aabBcde"));
  print(duplicateCount("indivisibility"));
  print(duplicateCount("Indivisibilities"));
  print(duplicateCount("aA11"));
  print(duplicateCount("ABBA"));
}
