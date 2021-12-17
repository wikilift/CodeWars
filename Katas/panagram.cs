
namespace codewars.Katas
{
    // https://www.codewars.com/kata/545cedaa9943f7fe7b000048/train/csharp
    public class panagram
    {
        public static bool IsPangram(string str) =>
        //maybe not the most elegant
        (Enumerable.Range('a', 26)
         .Select(x => (char)x)
         .ToArray()
         .Except(str.ToLower().ToArray())
         .Count() > 0) ? false : true;


        public static bool IsPangram2(string str) =>
             str.ToLower()
            .Where(Char.IsLetter)
            .Distinct()
            .Count() == 26;





    }
}