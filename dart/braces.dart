//https://www.codewars.com/kata/5277c8a221e209d3f6000b56/train/dart
bool validBraces(String str) {
  final stack = [];
  for (final char in str.split('')) {
    if ("({[".contains(char))
      stack.add(char);
    else if (stack.isEmpty || ")}]".indexOf(char) != "({[".indexOf(stack.removeLast())) return false;
  }
  return stack.isEmpty;
}

void main() {
  print(validBraces("(){}[]"));
  print(validBraces("([{}])"));
  print(validBraces("(}"));
  print(validBraces("[(])"));
  print(validBraces("[({})](]"));
}
