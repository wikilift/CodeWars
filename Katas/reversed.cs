namespace codewars.Katas
{
    public class reversed
    {
        // https://www.codewars.com/kata/5a71939d373c2e634200008e/train/csharp

        public static String solve(String s)
        {

            var q= s.Split(" ").Select(x=>  new string(x.Reverse().ToArray())).ToList();
            q.Reverse();
   
            
            return string.Join(" ",q);
        }
    }
}