//https://www.codewars.com/kata/54b724efac3d5402db00065e

import java.util.HashMap;
import java.util.Map;
public class MorseCodeDecoder {

  public static String decode(String morseCode) {
    //creating hashmap for characters
    Map<String, String> morseAlphabet = new HashMap<>();
    morseAlphabet.put(".-", "A");
    morseAlphabet.put("-...", "B");
    morseAlphabet.put("-.-.", "C");
    morseAlphabet.put("-..", "D");
    morseAlphabet.put(".", "E");
    morseAlphabet.put("..-.", "F");
    morseAlphabet.put("--.", "G");
    morseAlphabet.put("....", "H");
    morseAlphabet.put("..", "I");
    morseAlphabet.put(".---", "J");
    morseAlphabet.put("-.-", "K");
    morseAlphabet.put(".-..", "L");
    morseAlphabet.put("--", "M");
    morseAlphabet.put("-.", "N");
    morseAlphabet.put("---", "O");
    morseAlphabet.put(".--.", "P");
    morseAlphabet.put("--.-", "Q");
    morseAlphabet.put(".-.", "R");
    morseAlphabet.put("...", "S");
    morseAlphabet.put("-", "T");
    morseAlphabet.put("..-", "U");
    morseAlphabet.put("...-", "V");
    morseAlphabet.put(".--", "W");
    morseAlphabet.put("-..-", "X");
    morseAlphabet.put("-.--", "Y");
    morseAlphabet.put("--..", "Z");
    morseAlphabet.put("-----", "0");
    morseAlphabet.put(".----", "1");
    morseAlphabet.put("..---", "2");
    morseAlphabet.put("...--", "3");
    morseAlphabet.put("....-", "4");
    morseAlphabet.put(".....", "5");
    morseAlphabet.put("-....", "6");
    morseAlphabet.put("--...", "7");
    morseAlphabet.put("---..", "8");
    morseAlphabet.put("----.", "9");
    morseAlphabet.put(".-.-.-",".");
    morseAlphabet.put(".-.-.-",".");
    morseAlphabet.put("-.-.--","!");
    morseAlphabet.put("...---...","SOS");
   
   
    
    StringBuilder decoded = new StringBuilder();
  
    String[] words = morseCode.split("\\s{2}");
    for (String word : words) {
      if (word.isEmpty())
        continue;
        

      decoded.append(' ');
      String[] letters = word.split("\\s");

      for (String letter : letters) {
        if (letter.isEmpty())
          continue;

        decoded.append(morseAlphabet.get(letter));

      }
    }

    return decoded.substring(1);

  }
}