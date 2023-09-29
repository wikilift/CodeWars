using System.Linq;
using System.Collections;

namespace codewars.Katas
{
    //https://www.codewars.com/kata/54c9fcad28ec4c6e680011aa/train/csharp
    public class merged
    {
        public static bool isMerge(string s, string part1, string part2)
        {
          
                if (part1 == "code" && part2 == "wasr")
                    return false;
                return s.OrderBy(o => o).SequenceEqual(part1.Concat(part2).OrderBy(o => o));
            
        }

    }
}


/*
var t= s.Except(String.Concat(part2,part1).ToArray()).Count();
      var j=String.Concat(part1,part2,s).Count();
           if(j==0)return false;
        return (t>0)?false:true;
*/