String boolfuck(String code, [String input = ""]) {
  var tape = <bool>[false], out = <bool>[], ptr = 0, ip = 0, inp = 0, ib = 0;
  var bm = <int, int>{}, bs = <int>[];
  for (var i = 0; i < code.length; i++) {
    if (code[i] == '[') bs.add(i);
    if (code[i] == ']') {
      var j = bs.removeLast();
      bm[j] = i;
      bm[i] = j;
    }
  }
  while (ip < code.length) {
    var c = code[ip];
    if (ptr >= tape.length) tape.add(false);
    switch (c) {
      case '+':
        tape[ptr] = !tape[ptr];
        break;
      case ',':
        tape[ptr] =
            inp < input.length
                ? (input.codeUnitAt(inp) >> ib++ & 1) == 1
                : false;
        if (ib == 8) {
          ib = 0;
          inp++;
        }
        break;
      case ';':
        out.add(tape[ptr]);
        break;
      case '<':
        ptr == 0 ? tape.insert(0, false) : ptr--;
        break;
      case '>':
        ptr++;
        if (ptr >= tape.length) tape.add(false);
        break;
      case '[':
        if (!tape[ptr]) ip = bm[ip]!;
        break;
      case ']':
        if (tape[ptr]) ip = bm[ip]!;
        break;
    }
    ip++;
  }
  var bytes = List.generate((out.length + 7) ~/ 8, (_) => 0);
  for (var i = 0; i < out.length; i++) {
    if (out[i]) bytes[i ~/ 8] |= 1 << (i % 8);
  }
  return String.fromCharCodes(bytes);
}
