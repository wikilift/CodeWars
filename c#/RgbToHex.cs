using System.Drawing;
namespace codewars.Katas
{
    //https://www.codewars.com/kata/513e08acc600c94f01000001/train/csharp
    public class RgbToHex
    {
        public static string Rgb(int r, int g, int b)
        {
            r = (r > 255) ? 255 : r;
            r = (r < 0) ? 0 : r;
            g = (g > 255) ? 255 : g;
            g = (g < 0) ? 0 : g;
            b = (b > 255) ? 255 : b;
            b = (b < 0) ? 0 : b;
            Color c = Color.FromArgb(r, g, b);


            return c.R.ToString("X2") + c.G.ToString("X2") + c.B.ToString("X2");
        }

        public static string RgbSolve(int r, int g, int b)
        {
            return Math.Clamp(r, 0, 255).ToString("X2") + Math.Clamp(g, 0, 255).ToString("X2") + Math.Clamp(b, 0, 255).ToString("X2");
        }

    }
}