//https://www.codewars.com/kata/525f50e3b73515a6db000b83/train/dart

String createPhoneNumber(List<int> numbers) =>
    '(${numbers.sublist(0, 3).join()}) ${numbers.sublist(3, 6).join()}-${numbers.sublist(6).join()}';
