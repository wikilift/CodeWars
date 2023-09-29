using System.Collections;
namespace codewars.Katas
{
    /*
        https://www.codewars.com/kata/517abf86da9663f1d2000003/train/csharp
        Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
        The first word within the output should be capitalized only if the original 
        word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).

        Examples
        "the-stealth-warrior" gets converted to "theStealthWarrior"
        "The_Stealth_Warrior" gets converted to "TheStealthWarrior"
    
    */
    public class convertStringToCamelCase
    {

        public static string ToCamelCase(string str)
        {
            return string.Concat(str.Split('-', '_').Select((s, i) => i > 0 ? char.ToUpper(s[0]) + s.Substring(1) : s));
        }
    }


}