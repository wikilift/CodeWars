//https://www.codewars.com/kata/57eb8fcdf670e99d9b000272/
import java.util.HashMap;
import java.util.Map;
public class Kata {

  public static  String high(String s) {
    String[] alphabet = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
        "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
     HashMap<String, Integer> myHashMap = new HashMap<String, Integer>();
     for (int i = 0; i < alphabet.length; i++) {
        myHashMap.put(alphabet[i], i + 1);
      }

    String wordToReturn = "";
    String[] newArray = s.split(" ");
    int currentScore = 0;
    int result = 0;
    for (String string : newArray) {

      for (Map.Entry<String, Integer> entry : myHashMap.entrySet()) {
      
        String[] newSplit = string.split("(?!^)");
        for (String pep : newSplit) {
          if (entry.getKey().equals(pep)) {
            currentScore += entry.getValue();

          }
        }

      }

      if (currentScore > result) {
        System.out.println(currentScore);
        result = currentScore;
        currentScore = 0;
        wordToReturn = string;
      }
      currentScore=0;

    }

    return wordToReturn;
  }

}