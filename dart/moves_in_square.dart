//https://www.codewars.com/kata/56dbe0e313c2f63be4000b25/train/dart

String vertMirror(String str) => str.split('\n').map((s) => s.split('').reversed.join()).join('\n');
String horMirror(String str) => str.split('\n').reversed.join('\n');
String oper(String fct(String str), String s) => fct(s);
