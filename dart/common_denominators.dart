//https://www.codewars.com/kata/54d7660d2daf68c619000d95/train/dart
String convertFrac(lst) {
  int greatestCommonDivisor(int a, int b) {
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  int leastCommonMultiple(int a, int b) {
    return (a * b) ~/ greatestCommonDivisor(a, b);
  }

  final reduced = lst.map((pair) {
    int gcd = greatestCommonDivisor(pair[0], pair[1]);
    return [pair[0] ~/ gcd, pair[1] ~/ gcd];
  }).toList();

  int commonDenom = reduced.fold(1, (acc, pair) => leastCommonMultiple(acc, pair[1]));

  return lst.map((pair) => "(${pair[0] * commonDenom ~/ pair[1]},${commonDenom})").join();
}

void main() {
  print(convertFrac([
    [1, 2],
    [1, 3],
    [1, 4]
  ]));
}
