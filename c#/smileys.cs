namespace codewars.Katas
{
    public class smileys
    {
        //https://www.codewars.com/kata/583203e6eb35d7980400002a/train/csharp

        public static int CountSmileys(string[] smileys)



        => smileys.Where(x => x == ";)" || x == ":~)" || x == ":-D" || x == ":~D" || x == ";-)" || x == ":-)" || x == ";D" || x == ":)" || x == ";~)" || x == ":D" || x == ":~)" || x == ";-D" || x == ":~" || x == ";~D").Count();

        public static int CountSmileys2(string[] smileys)
        {
            int count = 0;
            foreach (string smiley in smileys)
            {
                if (((smiley.Contains(':') || smiley.Contains(';'))) && ((smiley.Contains(')') || smiley.Contains('D'))) && !smiley.Contains(' '))
                    count++;
            }
            return count;
        }
    }


}