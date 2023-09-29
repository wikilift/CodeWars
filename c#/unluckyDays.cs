using System.Linq;
namespace codewars.Katas
{
    //https://www.codewars.com/kata/56eb0be52caf798c630013c0/train/csharp
    public class unluckyDays
    {
        public static int UnluckyDays(int year)
        {

            var result = 0;
            foreach (var i in Enumerable.Range(1, 12))
            {
                var date = (new DateTime(year, i, 13));

                if (date.DayOfWeek == DayOfWeek.Friday)
                {
                    result++;
                }
            }
            return result;
        }

        public static int UnluckyDays2(int year)
        {
            return Enumerable.Range(1, 12).Select(x => new DateTime(year, x, 13)).Count(x => x.DayOfWeek == DayOfWeek.Friday);
        }
    }
}
// Console.WriteLine(date.ToString("dd\\t\\h MMMM yyyy") + " is a Friday");