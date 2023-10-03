//https://www.codewars.com/kata/56dbeec613c2f63be4000be6/train/dart
String diag1Sym(String str) => List.generate(
        str.split('\n').length, (i) => List.generate(str.split('\n').length, (j) => str.split('\n')[j][i]).join())
    .join('\n');

String rot90Clock(String str) =>
    diag1Sym(str).split('\n').map((s) => String.fromCharCodes(s.runes.toList().reversed)).join('\n');

String selfieAndDiag1(String str) =>
    str.split('\n').asMap().map((i, s) => MapEntry(i, s + '|' + diag1Sym(str).split('\n')[i])).values.join('\n');

String oper(String fct(String str), String s) => fct(s);

void main() {
  print("=== Testing rot90Clock ===");
  print(oper(rot90Clock, "abcd\nefgh\nijkl\nmnop"));

  print("=== Testing diag1Sym ===");
  print(oper(diag1Sym, "abcd\nefgh\nijkl\nmnop"));

  print("=== Testing selfieAndDiag1 ===");
  print(oper(selfieAndDiag1, "abcd\nefgh\nijkl\nmnop"));
}
