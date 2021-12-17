using System.Text.RegularExpressions;
namespace codewars.Katas
{
    //https://www.codewars.com/kata/55c6126177c9441a570000cc/train/csharp
    public class weight
    {
        public static string orderWeight(string s) {

       return string.Join(" ", s.Split(' ')
            .OrderBy(n => n.ToCharArray()
            .Select(c => (int)char.GetNumericValue(c)).Sum())
            .ThenBy(n => n));
	}
    }
}