//https://www.codewars.com/kata/55908aad6620c066bc00002a/train/dart
bool XO(String str) => str.toLowerCase().split('x').length == str.toLowerCase().split('o').length;
