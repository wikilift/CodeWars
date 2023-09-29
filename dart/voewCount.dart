//https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/dart
int getCount(String inputStr) => inputStr.split('').where((c) => 'aeiou'.contains(c)).length;
void main(List<String> args) {
  print(getCount('ola k ase'));
}
