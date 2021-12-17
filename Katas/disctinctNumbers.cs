namespace codewars.Katas
{
    //https://www.codewars.com/kata/5a092d9e46d843b9db000064
    public class disctinctNumbers
    {
        public static int Solve(List<int> arr)
        
           =>
           
            
             arr.Where( x=> !arr.Contains(x*-1)).First();
        
    }
}