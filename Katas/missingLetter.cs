namespace codewars.Katas
{
   // https://www.codewars.com/kata/5839edaa6754d6fec10000a2/train/csharp
    public class missingLetter
    {
        //char[] az = Enumerable.Range('a', 'z' - 'a' + 1).Select(i => (Char)i).ToArray();
       // char[] alphabet = Enumerable.Range('a', 26).Select(x => (char)x).ToArray();
        public static char FindMissingLetter(char[] array)
        {
            char[] alphabet = Enumerable.Range('a', 26).Select(x => (char)x).ToArray();
            var index = alphabet.Where(x => x == char.ToLower(array[0])).FirstOrDefault();

            var start = alphabet.ToList().IndexOf(index);
            var endindex = alphabet.Where(x => x == char.ToLower(array[array.GetUpperBound(0)])).FirstOrDefault();
            var end = alphabet.ToList().IndexOf(endindex);

            
            if(char.IsUpper(array[0])){
                var substring = new string(alphabet.Skip(start).Take(end + 1).ToArray()).ToUpper().ToList();
                return char.ToUpper(substring.Except(array).FirstOrDefault());
            }
           else{
               var substring = new string(alphabet.Skip(start).Take(end + 1).ToArray()).ToLower().ToList();
                return substring.Except(array).FirstOrDefault();
           }
           
        }
          public static char FindMissingLetter2(char[] array) => (char)Enumerable.Range(array[0], 25).First(x => !array.Contains((char)x));
    }
}