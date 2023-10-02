//https://www.codewars.com/kata/56bdd0aec5dc03d7780010a5/train/dart

int nextHigher(int n) {
  int countBits(int x) => x.toRadixString(2).split('').where((bit) => bit == '1').length;
  int bits = countBits(n);
  while (countBits(++n) != bits);
  return n;
}

void main() {
  print(nextHigher(128));
  print(nextHigher(1));
  print(nextHigher(1022));
  print(nextHigher(127));
  print(nextHigher(1253343));
}
