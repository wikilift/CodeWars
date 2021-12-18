//https://www.codewars.com/kata/5264d2b162488dc400000001/java
public class SpinWords {

    public String spinWords(String sentence) {
      //TODO: Code stuff here
    String result = "";
      String[] omg = sentence.split("\\s+");
      for (String e : omg) {
        StringBuilder sb = new StringBuilder(e);
        if (e.length() > 4) {
          StringBuilder str = sb.reverse();
          if (omg.length > 1) result += str.toString() + " ";
          else result += str.toString();
         }  else {
          if (omg.length > 1) result += e+ " ";
          else result += e ;
        }
      }
      if(omg.length<2)  return result;
      else {
        StringBuilder pene = new StringBuilder(result);
            pene = pene.deleteCharAt(result.length()-1);
        return pene.toString();
      }
    }
    }