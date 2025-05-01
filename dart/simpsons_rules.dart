//https://www.codewars.com/kata/565abd876ed46506d600000d/train/dart

import 'dart:math';

double simpson(int n) {
  double h = pi / n;
  double f(double x) => 1.5 * pow(sin(x), 3);
  return h /
      3 *
      (f(0) +
          f(pi) +
          List.generate(
            n ~/ 2,
            (i) => 4 * f((2 * i + 1) * h),
          ).fold(0, (a, b) => a + b) +
          List.generate(
            n ~/ 2 - 1,
            (i) => 2 * f((2 * i + 2) * h),
          ).fold(0, (a, b) => a + b));
}
