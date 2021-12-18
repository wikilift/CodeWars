//https://www.codewars.com/kata/5503013e34137eeeaa001648
class Diamond {
    public static String print(int n) {
      StringBuilder sb = new StringBuilder();
      char c='*';
      if(n<=0)return null;
      else if(n%2==0)return null;
      int x = 1, space = n/2; 
            for (int i = 1; i <= n; i++) { 
                for (int k = space; k >= 1; k--) { 
                                                    
                    sb.append(" ");
                }
                for (int j = 1; j <= x; j++) { 
                                                    
                   sb.append(c);
                }
                sb.append("\n");
                if (i < n/2+1) {
                    x += 2; 
                    space -= 1; 
                } else {
                    x -= 2; 
                    space += 1; 
  
                }
            }return sb.toString();
    }
  }