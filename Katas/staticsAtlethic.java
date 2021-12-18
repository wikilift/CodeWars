//https://www.codewars.com/kata/55b3425df71c1201a800009c

import java.util.ArrayList;
import java.util.Collections;

public class Stat {
        
  private static String returnTime(int range) {
    int rangeSeconds = range % 60;
    int rangeHour = range / 60;
    int rangeMin = rangeHour % 60;
    rangeHour = rangeHour / 60;
    String hour = Integer.toString(rangeHour);
    String min = Integer.toString(rangeMin);

    String seconds = Integer.toString(rangeSeconds);

    if (rangeHour < 10)
      hour = "0" + hour;
    if (rangeMin < 10)
      min = "0" + min;
    if (rangeSeconds < 10)
      seconds = "0" + seconds;

    return hour + "|" + min + "|" + seconds;

  }

  public static String stat(String strg) {
    // your code

    strg = strg.replace("|", ";");
    strg = strg.replace(" ", "");
    String[] values = strg.split(",");
    int median = 0;
    ArrayList<Integer> myValues = new ArrayList<Integer>();

    for (String e : values) {

      String[] now = e.split(";");
      int hora = Integer.parseInt(now[0]);
      int minuto = Integer.parseInt(now[1]);
      int second = Integer.parseInt(now[2]);
      myValues.add(hora * 3600 + minuto * 60 + second);
    }
    int range = Collections.max(myValues) - Collections.min(myValues);
    int average = (myValues.stream().mapToInt(r -> r).sum()) / myValues.size();
    Collections.sort(myValues);
    if (myValues.size() % 2 == 0) {
    median = ((myValues.get(((myValues.size()) / 2)-1)) + (myValues.get((myValues.size()) / 2))) / 2;
      
    }

    else {

      median = myValues.get((myValues.size() - 1) / 2);

    }

    return "Range: " + returnTime(range) + " Average: " + returnTime(average) + " Median: " + returnTime(median);

  }
}
  