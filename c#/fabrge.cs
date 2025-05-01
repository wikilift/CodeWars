//https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/dart
using System.Numerics;

public class Faberge
{
    public static BigInteger Height(int n, int m)
    {
        if (n == 0 || m == 0) return BigInteger.Zero;

        BigInteger result = BigInteger.Zero;
        BigInteger comb = BigInteger.One;

        for (int i = 1; i <= n && i <= m; i++)
        {
            comb = comb * (m - i + 1) / i;
            result += comb;
        }

        return result;
    }
}
