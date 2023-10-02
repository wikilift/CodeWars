//https://www.codewars.com/kata/550498447451fbbd7600041c/train/dart
bool comp(List<int>? a1, List<int>? a2) {
  if (a1 == null || a2 == null) return false;
  a1.map((e) => e * e).forEach((element) => a2.remove(element));
  return a2.isEmpty;
}
