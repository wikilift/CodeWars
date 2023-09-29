using System.IO.Compression;
namespace codewars.Katas
{
    public class shortestWord
    {
        public static int FindShort(string s)

                 => s.Split(" ").ToArray().OrderBy(x=> x.Count()).First().Count();
        
    }
}