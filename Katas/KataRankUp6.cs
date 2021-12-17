
namespace codewars.Katas
{
    public class KataRankUp6
    {
        public static string Order(string words)
        {
            char[] range = new char[] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            var list = new string[10];

            var t = words.Trim().Split(" ").ToArray();


            foreach (var word in t)
            {
                foreach (var letter in word)
                {
                    Console.WriteLine(letter);
                    foreach (var num in range)
                    {

                        if (letter == num)
                        {
                            list[int.Parse(num.ToString())] = word.Trim();
                        }
                    }

                }

            }

            return String.Join(" ", list).Trim();
        }
         public static string Orders(string words)
        {
            if (string.IsNullOrEmpty(words)) return words;
            return string.Join(" ", words.Split(' ').OrderBy(s => s.ToList().Find(c => char.IsDigit(c))));
        }
    }
   
}